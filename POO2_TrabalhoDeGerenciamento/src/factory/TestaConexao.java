/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package factory;
import java.sql.SQLException;
/**
 *
 * @author icegurto
 */
public class TestaConexao {
    public static void main(String[] args) throws SQLException {
        java.sql.Connection connection = new ConnectionFactory().getConnection();
        System.out.print("conexao aberta");
        connection.close();
    }
    
}
