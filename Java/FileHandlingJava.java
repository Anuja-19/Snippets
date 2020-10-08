
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.FileWriter;
import java.io.IOException;

/**
 * FileHandlingJava
 */
public class FileHandlingJava {

    // file details
    String fileName;
    File file;

    // while creating new file
    FileHandlingJava(String fileName, String fileExtension) {
        // maintain fileName
        this.fileName = fileName + "." + fileExtension;

        // create new file else mention that it already exists
        try {
            this.file = new File(this.fileName);
            if (this.file.createNewFile()) {
                System.out.println("File created: " + this.file.getName());
            } else {
                System.out.println("File already exists.");
            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    // create new file
    public static FileHandlingJava CreatingNewFileWithName(String fileNameString, String fileExtensionString) {
        return new FileHandlingJava(fileNameString, fileExtensionString);
    }

    // for writing data to the file
    static void WriteDataToFile(FileHandlingJava file, String data) {
        try {
            FileWriter fileWriter = new FileWriter(file.fileName);
            fileWriter.write(data);
            fileWriter.close();
            System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    // for deleting the file
    static void DeleteFileFromMachine(FileHandlingJava file) {
        if (file.file.delete()) {
            // normal deletion
            System.out.println("Deleted the file: " + file.file.getName());
        } else {
            // if not found
            System.out.println("Failed to delete the file.");
        }
    }

    // for printing file details
    static void PrintFileInformation(FileHandlingJava file) {
        if (file.file.exists()) {
            System.out.println("File name: " + file.file.getName());
            System.out.println("Absolute path: " + file.file.getAbsolutePath());
            System.out.println("Writeable: " + file.file.canWrite());
            System.out.println("Readable " + file.file.canRead());
            System.out.println("File size in bytes " + file.file.length());
        } else {
            System.out.println("The file does not exist.");
        }
    }

    // for reading data from the file
    // Reading data from this file and displaying on the screen
    static void ReadDataFromFile(FileHandlingJava file) {
        try {
            Scanner myReader = new Scanner(file.file);
            // check for next lines and print them if present
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                System.out.println(data);
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        String FILE_NAME = "new_file";
        String FILE_EXTENSION = "txt";
        String DATA_TO_BE_WRITTEN = "This is the newly created file: Hurray..!!";

        // created file
        FileHandlingJava ourFile = CreatingNewFileWithName(FILE_NAME, FILE_EXTENSION);

        // written data to file
        WriteDataToFile(ourFile, DATA_TO_BE_WRITTEN);

        // reading data from the file and displaying it
        ReadDataFromFile(ourFile);

        // printing details about our file
        PrintFileInformation(ourFile);

        // deleting the file
        DeleteFileFromMachine(ourFile);
    }

}
