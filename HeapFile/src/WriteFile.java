import java.io.*;
import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;

public class WriteFile {
    /*
      read the csv file and then use DataOutputStream to write it into a binary file.
       And it will also calculate the pages it need and numbers of records it loaded.
     */
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

    /*creating dataset/record and apply the offset when necessary.
       dataoffset = the size of previous records
    */
    private byte[] dataset(byte[] data, String[] words, int extraPage) {
        byte[] dID = intToByteArr(extraPage);
        int DA_NAME_SIZE = 40;
        int DEVICE_ID_SIZE = 15;
        int ARRIVAL_TIME_SIZE = 30;
        int DEPARTURE_TIME_SIZE = 30;
        int DURATION_SECONDS_SIZE = 15;
        int STREET_MARKER_SIZE = 20;
        int SIGN_SIZE = 40;
        int AREA_SIZE = 20;
        int STREET_ID_SIZE = 15;
        int STREET_NAME_SIZE = 30;
        int BETWEEN_ST_1_SIZE =30;
        int BETWEEN_ST_2_SIZE = 30;
        int SIDE_OF_STREET_SIZE = 15;
        int IN_VIOLATEION_SIZE = 15;

        int DA_NAME_OFFSET = DA_NAME_SIZE;
        int DEVICE_ID_OFFSET = DA_NAME_SIZE + DEVICE_ID_SIZE;
        int ARRIVAL_TIME_OFFSET = DEVICE_ID_OFFSET + ARRIVAL_TIME_SIZE;
        int DEPARTURE_TIME_OFFSET = ARRIVAL_TIME_OFFSET + DEPARTURE_TIME_SIZE;
        int DURATION_SECONDS_OFFSET = DEPARTURE_TIME_OFFSET + DURATION_SECONDS_SIZE;
        int STREET_MARKER_OFFSET = DURATION_SECONDS_OFFSET + STREET_MARKER_SIZE;
        int SIGN_OFFSET = STREET_MARKER_OFFSET + SIGN_SIZE;
        int AREA_OFFSET = SIGN_OFFSET + AREA_SIZE;
        int STREET_ID_OFFSET = AREA_OFFSET + STREET_ID_SIZE;
        int STREET_NAME_OFFSET = STREET_ID_OFFSET + STREET_NAME_SIZE;

        System.arraycopy(dID, 0, data, 0, dID.length);
        createByteArr(words[0], DA_NAME_SIZE, DA_NAME_OFFSET, data);
        createByteArr(words[1], DEVICE_ID_SIZE, DEVICE_ID_OFFSET, data);
        createByteArr(words[2], ARRIVAL_TIME_SIZE, ARRIVAL_TIME_OFFSET, data);
        createByteArr(words[3], DEPARTURE_TIME_SIZE, DEPARTURE_TIME_OFFSET, data);
        createByteArr(words[4], DURATION_SECONDS_SIZE, DURATION_SECONDS_OFFSET, data);
        createByteArr(words[5], STREET_MARKER_SIZE , STREET_MARKER_OFFSET, data);
        createByteArr(words[6], SIGN_SIZE , SIGN_OFFSET, data);
        createByteArr(words[7], AREA_SIZE, AREA_OFFSET, data);
        createByteArr(words[8], STREET_ID_SIZE, STREET_ID_OFFSET, data);
        createByteArr(words[9], STREET_NAME_SIZE , STREET_NAME_OFFSET, data);
        createByteArr(words[10], BETWEEN_ST_1_SIZE , 269, data);
        createByteArr(words[11], BETWEEN_ST_2_SIZE, 270, data);
        createByteArr(words[12], SIDE_OF_STREET_SIZE, 271, data);
        createByteArr(words[13], IN_VIOLATEION_SIZE, 272, data);
        return data;
    }

    //Convert ints to string
    public byte[] intToByteArr(int i) {
        ByteBuffer buffer = ByteBuffer.allocate(4);
        buffer.putInt(i);
        return buffer.array();
    }
}
