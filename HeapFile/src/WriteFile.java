import java.io.*;

public class WriteFile {

    public void WriteToFile(String fileName, String HeapFileName) {

        try {
            BufferedReader reader = null;
            reader = new BufferedReader(new FileReader(fileName));
            FileOutputStream output = new FileOutputStream(HeapFileName);
            ObjectOutputStream oos = new ObjectOutputStream(output);
            String line;
            line = reader.readLine();
            while ((line = reader.readLine()) != null) {
                String[] words = line.split(",");

                oos.writeBytes(words[0]);
                oos.writeBytes(words[1]);
                oos.writeBytes(words[2]);
                oos.writeBytes(words[3]);
//                System.out.println(line);
            }
            oos.flush();
            oos.close();
        } catch (FileNotFoundException e) {
            System.out.println("File does not exist");
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public int count(String fileName) throws IOException {
        InputStream is = new BufferedInputStream(new FileInputStream(fileName));
        byte[] bytes = new byte[1024];
        int count = 0;
        int readChars = 0;
        boolean empty = true;
        while ((readChars = is.read(bytes)) != -1) {
            empty = false;
            for (int i = 0; i < readChars; i++) {
                if (bytes[i] == '\n') {
                    count++;
                }
            }
        }
//        System.out.println("Number of records loaded: ");
        return (count == 0 && !empty) ? 1 : count;

    }
}
