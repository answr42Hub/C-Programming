package com.company;

import java.io.IOException;
import java.io.RandomAccessFile;

public class Main {

    public static void main(String[] args) {

        long offsetValue = 0, sizeValue = 0;
        int fileNameIndex = 0;
        boolean doNotPrint = false;
        byte minLength = 4;

        try {
            for(int k = 0; k < args.length; k++) {
                if(args[k].compareTo("-f") == 0) {
                    fileNameIndex = k;
                }
            }
                RandomAccessFile file = new RandomAccessFile(args[fileNameIndex+1], "r");

            for(int i = 0; i < args.length; i += 2) {
                switch(args[i]) {
                    case "-o" :
                        if(Long.parseLong(args[i+1]) >= 0 && Long.parseLong(args[i+1]) < file.length()) {
                            offsetValue = Integer.parseInt(args[i+1]);
                        }
                        else {
                            doNotPrint = true;
                            i = args.length;
                            printUsage();
                        }
                        break;

                    case "-l" :
                        if((Long.parseLong(args[i+1]) > 0) && Long.parseLong(args[i+1]) < file.length()) {
                            sizeValue = Long.parseLong(args[i+1]);
                        }
                        else {
                            doNotPrint = true;
                            i = args.length;
                            printUsage();
                        }
                        break;

                    case "-f" :
                        boolean lengthIsHere = false;
                        for(int j = 0; j < args.length; j++) {
                            if(args[j].compareTo("-l") == 0 && Integer.parseInt(args[j+1]) > 0) {
                                lengthIsHere = true;
                            }
                        }

                        if(!lengthIsHere) {
                            sizeValue = file.length();
                        }

                        break;

                    case "-s" :
                        doNotPrint = true;
                        if(args.length == 4 || args.length == 6) {
                            minLength = Byte.parseByte(args[i+1]);
                        }
                        break;

                    case "-i" :
                        if(args.length == 3) {
                            printFormat(file);
                            doNotPrint = true;
                        }

                        break;

                    default :
                        break;
                }
            }
            if(!doNotPrint && sizeValue <= (file.length() - offsetValue)) {
                printData(file, offsetValue, sizeValue);
            }
            else if(args[0].compareTo("-s") == 0 || args[2].compareTo("-s") == 0 || args[args.length-1].compareTo("-s") == 0 || args[args.length-2].compareTo("-s") == 0) {
                printStrings(file, minLength, sizeValue);
            }

        }
        catch(IOException e) {
            printUsage();
        }

    }

    public static void printData(RandomAccessFile file, long offset, long length) throws IOException {
        long tempHex;
        StringBuilder lineSeg = new StringBuilder();
        long posColDebut = (offset-(offset/16)*16);
        long posLineDebut = offset/16;
        long posColFin = (offset+length)-(((offset+length)/16)*16);
        long posLineFin = (offset+length)/16;

        file.seek(offset);
        System.out.println("\u001B[31m           0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f ASCII");
        for(long j = posLineDebut; j <= posLineFin; j++) {
            if(j != file.length()/16) {
                System.out.printf("\u001B[31m0x%06x" + "0", j);
            }

            for(long i = 0; i < 16; i++) {
                if((i < posColDebut && (j == posLineDebut)) || (i >= posColFin && (j == posLineFin))) {
                    System.out.print("   ");
                    lineSeg.append(" ");
                }
                else {
                    tempHex = file.read();
                    System.out.printf("\u001B[34m %02x", tempHex);
                    if(tempHex < 32) {
                        lineSeg.append('.');
                    }
                    else {
                        lineSeg.append((char) tempHex);
                    }
                }
            }

            System.out.printf("\u001B[37m %s%n", lineSeg);
            lineSeg = new StringBuilder();
       }file.close();

    }

    public static void printUsage() {
        System.out.println("""
                    Une erreur s'est produite, Voici comment utiliser le programme en ligne de commade :

                    -o N -l N -f nomDuFichier.ext [-s, -i]
                    (-o) facultatif : La valeur du décalage qui doit être >= 0 et < que la taille du fichier.
                    (-l) facultatif : La valeur de la taille qui doit être > 0 et < que la taille du fichier - le décalage.
                    (-f) obligatoire : La valeur du nom du fichier qui doit être un fichier existant.
                    (-s) facltatif : (valeur par défaut : 4) pourrait permettre d'afficher les chaines de
                    caractères du fichier, plutôt que ses données, selon la taille minimum passée en paramètre.
                    (-i) (facultatif) : (aucun paramètre) Affiche lr systeme d'exploitation et son type de machine.""");
    }

    public static void printStrings(RandomAccessFile file, byte minLength, long length) throws IOException{
        StringBuilder strRead = new StringBuilder();
        int charRead;
        if(length <= file.length()) {
            for(int i = 0; i < length; i++) {
                charRead = file.read();
                while(charRead > 31 && charRead <= 127 || charRead == 10 || 13 == charRead) {
                    if(charRead == 10) {
                        strRead.append("\\n");
                    }
                    else if(charRead == 13) {
                        strRead.append("\\r");
                    }
                    else {
                        strRead.append((char) charRead);
                    }
                    charRead = file.read();
                    ++i;
                }

                if(strRead.length() >= minLength && charRead == 0) {
                    System.out.println(strRead);
                }
                strRead = new StringBuilder();
            }
        }
    }

    public static void printFormat(RandomAccessFile file) throws IOException {

        long i = 0;
        while(i < file.length()) {
            if(file.read() == 80 && file.read() == 69) {
                System.out.println("OS : Windows");
                if(file.read() == 0 && file.read() == 0 && file.read() == 100 && file.read() == 134) {
                    System.out.println("Machine: x64");
                }
                else {
                    System.out.println("Machine: x32");
                }
                i = file.length();
            }
            ++i;
        }

        file.seek(0);
        int readByte;
        if (file.read() == 127 && file.read() == 69 && file.read() == 76 && file.read() == 70) {
            System.out.println("OS : Linux");
            file.seek(0x12);
            readByte = file.read();
            if(readByte == 0x3E) {
                System.out.println("Machine : AMD x86-64");
            }
            else if(readByte == 0xB7) {
                System.out.println("Machine : ARM 64-bits");
            }
            else {
                System.out.println("Autre");
            }
        }
        file.seek(0);
        if (file.read() == 207 && file.read() == 250 && file.read() == 237 && file.read() == 254) {
            System.out.println("OS : macOS");
            System.out.println("Machine : x64");

        }
        file.seek(0);
        if (file.read() == 0xce && file.read() == 250 && file.read() == 237 && file.read() == 254) {
            System.out.println("OS : macOS");
            System.out.println("Machine : x32");
        }



    }

}
