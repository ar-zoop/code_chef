import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {    

    public static void main(String[] args) {
        
        Regex_Test tester = new Regex_Test();
        tester.checker("^([ab])[ab]*\\1$|^[ab]$"); // Use \\ instead of using \ 
    
    }
}

class Regex_Test {