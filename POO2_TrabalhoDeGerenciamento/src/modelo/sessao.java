/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

/**
 *
 * @author icegurto
 */
public class sessao {
    private static int idUsuario;
    private static String email;

    public static void setIdUsuario(int id) {
        idUsuario = id;
    }

    public static int getIdUsuario() {
        return idUsuario;
    }

    public static void setEmail(String em) {
        email = em;
    }

    public static String getEmail() {
        return email;
    }
    
}
