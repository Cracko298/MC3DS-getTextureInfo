public class Main {
    static {
        System.loadLibrary(".\\getTextureInfo.dll");
    }

    public static native String getFileFormat(String input);

    public static void main(String[] args) {
        String inputString = ".\\steve.3dst";
        String result = getFileFormat(inputString);
        System.out.println(result);
    }
}