import java.io.IOException;

public class dbload {
    public static void main(String[] args) {
        WriteFile writeFile = new WriteFile();
        // Check command line parameters
        if (args.length != 3) {
            System.out.println("Do not have enough parameters");
            return;
        }

        //Check second command line parameters
        String pageSizeStr = args[1];
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

        //Check whether the file existed
        String fileName = args[2];
        if (fileName == null || fileName.isEmpty()) {
            System.out.println("File does not exist");
            return;
        }
        String heapFile = "heap." + pageSizeStr;

        // Calculate the time to create heap file
        long beginTime = System.currentTimeMillis();
        writeFile.WriteToFile(fileName, heapFile, pageSize);
        long endTime = System.currentTimeMillis();
        System.out.println("Time used to create file is: " + (endTime - beginTime) + "ms");


    }
}
