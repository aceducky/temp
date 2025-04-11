import java.util.Scanner;

public class Hill {
    static int[][] km = new int[2][2];
    static int[][] ikm = new int[2][2];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 2x2 key matrix:");
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                km[i][j] = sc.nextInt();
        System.out.println("Enter even length plaintext: ");
        String pt = sc.next().toUpperCase();
        if (pt.length() % 2 != 0)
            pt += "X";
        String ct = transform(pt, km);
        System.out.println("Ciphertext: " + ct);
        if (calculateInverse()) {
            String dt = transform(ct, ikm);
            System.out.println("Decrypted: " + dt);
        } else {
            System.out.println("Key not invertible.");
        }
        sc.close();
    }

    static String transform(String text, int[][] matrix) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < text.length(); i += 2) {
            int p0 = text.charAt(i) - 'A';
            int p1 = text.charAt(i + 1) - 'A';
            int r0 = (matrix[0][0] * p0 + matrix[0][1] * p1) % 26;
            int r1 = (matrix[1][0] * p0 + matrix[1][1] * p1) % 26;
            r0 = (r0 + 26) % 26; // ensure non-negative
            r1 = (r1 + 26) % 26;
            sb.append((char) (r0 + 'A'));
            sb.append((char) (r1 + 'A'));
        }
        return sb.toString();
    }

    static boolean calculateInverse() {
        int det = km[0][0] * km[1][1] - km[0][1] * km[1][0];
        det = ((det % 26) + 26) % 26;
        int inv = -1;
        for (int i = 0; i < 26; i++) {
            if ((det * i) % 26 == 1) {
                inv = i;
                break;
            }
        }
        if (inv == -1)
            return false;
        ikm[0][0] = (km[1][1] * inv) % 26;
        ikm[0][1] = (-km[0][1] * inv) % 26;
        ikm[1][0] = (-km[1][0] * inv) % 26;
        ikm[1][1] = (km[0][0] * inv) % 26;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                ikm[i][j] = ((ikm[i][j] % 26) + 26) % 26;
        return true;
    }
}

_____

import javax.crypto.*;
import java.util.Base64;

public class SymmetricEncryption {
    public static void main(String[] args) throws Exception {
        String algorithm = "DES"; // or "AES", "Blowfish"
        KeyGenerator kg = KeyGenerator.getInstance(algorithm);
        SecretKey key = kg.generateKey();
        Cipher cipher = Cipher.getInstance(algorithm);
        String plainText = "Hello world";
        
        cipher.init(Cipher.ENCRYPT_MODE, key);
        byte[] encBytes = cipher.doFinal(plainText.getBytes());
        String encString = Base64.getEncoder().encodeToString(encBytes);
        System.out.println("Encrypted: " + encString);
        
        cipher.init(Cipher.DECRYPT_MODE, key);
        byte[] decBytes = cipher.doFinal(Base64.getDecoder().decode(encString));
        System.out.println("Decrypted: " + new String(decBytes));
    }
}

_____

import java.security.MessageDigest;

public class Hashing {
    public static String getHash(String input, String algorithm) throws Exception {
        MessageDigest md = MessageDigest.getInstance(algorithm);
        byte[] digest = md.digest(input.getBytes());
        StringBuilder sb = new StringBuilder();
        for (byte b : digest) {
            sb.append(String.format("%02x", b));
        }
        return sb.toString();
    }

    public static void main(String[] args) throws Exception {
        String text = "Hello world";
        String sha1 = getHash(text, "SHA-1");
        System.out.println("SHA-1: " + sha1);
    }
}
