import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.ByteBuffer;

public class dbquery {
    public static void main(String[] args) {

        // Check command line parameters
        if (args.length != 4) {
            System.out.println("Do not have correct numbers of parameters");
            return;
        }

        //Check whether the file existed
        String[] text = new String[3];
        text[0] = args[0];
        text[1] = args[1];
        text[2] = args[2];
//        String text = args[0];
        if (text[0] == null) {
            System.out.println("Please input the searching text");
            return;
        }


        //Check second command line parameters
        String pageSizeStr = args[3];
        int pageSize = 0;
        try {
            pageSize = Integer.parseInt(pageSizeStr);
            if (pageSize == 0) {
                System.out.println("Please specify the page size");
                return;
            }
        } catch (Exception e) {
            System.out.println("page size must be an integer.");
            return;
        }
        String heapFileName = "heap." + pageSizeStr;

        // Calculate the time to create heap file
        long beginTime = System.currentTimeMillis();
        textSearch(String.valueOf(text), heapFileName, pageSize);
        long endTime = System.currentTimeMillis();
        System.out.println("Time used to search the text is: " + (endTime - beginTime) + "ms");


    }

    public static void textSearch(String text, String filename, int pageSize) {
        FileInputStream fis = null;
        boolean hasNextPage = true;
        boolean hasData=true;
        int dID = 0;
        int dataLength = 0;
        int pageCount = 0;
        int dataCount = 0;
        try {
            fis = new FileInputStream(filename);
            while (hasNextPage) {
                byte[] page = new byte[pageSize];
                byte[] number = new byte[4];
                fis.read(page, 0, pageSize);
                System.arraycopy(page, page.length - 4, number, 0, 4);
                hasData = true;

                while (hasData) {
                    byte[] data = new byte[315];
                    byte[] dataArr = new byte[4];
                    System.arraycopy(page, dataLength, data, 0, 315);
                    System.arraycopy(data, 0, dataArr, 0, 4);
                    dID = ByteBuffer.wrap(dataArr).getInt();
                    if (dID != dataCount) {
                        hasData = false;
                    }else{
                        displayText(text, data);
                    }
                    dataCount++;
                }
                if ((ByteBuffer.wrap(number).getInt()) != dataCount) {
                    hasNextPage = false;
                }
                pageCount++;
            }
        } catch (FileNotFoundException e) {
            System.out.println("file: " + filename + " does not exist");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void displayText(String text, byte[] data) {
        String record = new String(data);
//        String DA_NAME = record.substring(0,100);
        if (record.contains(text)) {
            System.out.println(record);
        }
    }
}
