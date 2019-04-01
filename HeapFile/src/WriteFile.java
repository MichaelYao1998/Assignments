import java.io.*;
import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;

public class WriteFile {

    public void WriteToFile(String fileName, String HeapFileName, int pageSize) {
        byte[] data = new byte[300];
        int PageNumber, dataNumber;
        PageNumber = dataNumber = 0;
        int extraPage = 0;
        DataOutputStream dos = null;
        BufferedReader reader = null;
        String nextLine = "";
        try {
            dos = new DataOutputStream(new FileOutputStream(HeapFileName));
            reader = new BufferedReader(new FileReader(fileName));
            String line;
            line = reader.readLine();
            while ((line = reader.readLine()) != null) {
                String[] words = line.split(",", -1);
                data = dataset(data, words, extraPage);
                extraPage++;
                dos.writeBytes(String.valueOf(data));
                if ((extraPage + 1) * 300 > pageSize) {
                    extraPage = 0;
                    PageNumber++;
                }
                dataNumber++;
            }

        } catch (FileNotFoundException e) {
            System.out.println("File" + fileName + " does not exist");
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (reader != null) {
                try {
                    if ((nextLine = reader.readLine()) == null) {
                        PageNumber++;
                    }
                    dos.close();
                    reader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        System.out.println("Number of pages used: " + PageNumber);
        System.out.println("Number of records loaded: " + dataNumber);

    }
    //creating a byte array and append them to dataset to the correct offset position

    public void createByteArr(String words, int size, int dataOffset, byte[] data) {
        byte[] content = new byte[size];
        byte[] source = words.trim().getBytes(StandardCharsets.UTF_8);
        if (!words.equals("")) {
            System.arraycopy(source, 0, content, 0, source.length);
        }
        System.arraycopy(content, 0, data, dataOffset, content.length);
    }

        //creating dataset/record and apply the offset when necessary
    public byte[] dataset(byte[] data, String[] words, int extraPage) {
        byte[] dID = intToByteArr(extraPage);
        System.arraycopy(dID,0,data,0,dID.length);
        createByteArr(words[0],40,15,data);
        createByteArr(words[1],15,55,data);
        createByteArr(words[2],30,70,data);
        createByteArr(words[3],30,100,data);
        createByteArr(words[4],15,130,data);
        createByteArr(words[5],20,145,data);
        createByteArr(words[6],40,165,data);
        createByteArr(words[7],20,205,data);
        createByteArr(words[8],15,225,data);
        createByteArr(words[9],30,240,data);
        createByteArr(words[10],30,270,data);
        createByteArr(words[11],30,270,data);
        createByteArr(words[12],15,271,data);
        createByteArr(words[13],15,272,data);
        return data;
    }

    //Convert ints to string
    public byte[] intToByteArr(int i) {
        ByteBuffer buffer = ByteBuffer.allocate(4);
        buffer.putInt(i);
        return buffer.array();
    }
}
