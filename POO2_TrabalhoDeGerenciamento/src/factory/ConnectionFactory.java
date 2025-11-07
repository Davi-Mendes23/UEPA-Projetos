/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package factory;
import java.sql.SQLException;
import java.sql.Connection;
import java.sql.DriverManager;
/**
 *
 * @author icegurto
 */
public class ConnectionFactory {
    public Connection getConnection() {
     try {
        Class.forName("com.mysql.jdbc.Driver");
        return DriverManager.getConnection("jdbc:mysql://localhost:3306/thiagobd","root", "Zakcaue1!");
     }
     catch(ClassNotFoundException e) {
        throw new RuntimeException(e);
     }catch(SQLException execao) {
        throw new RuntimeException(execao);
     }
    }
}
