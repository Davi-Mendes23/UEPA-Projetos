/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Dao;
import factory.ConnectionFactory;
import factory.HashUtil;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import modelo.usuario;
import java.sql.ResultSet;
import modelo.sessao;
/**
 *
 * @author icegurto
 */
public class UsuarioDAO {
    private Connection connection;

    Integer id;
    String nome;
    String email;
    String senha;
    String cpf;
    String verificar_admin;
    public UsuarioDAO() {
     this.connection = new ConnectionFactory().getConnection();
    }
    public void adicionarUsuario(usuario usuario) throws Exception {
    String sql = "INSERT INTO usuario(nome, email, senha, cpf) VALUES(?,?,?,?)";
     try {
     PreparedStatement stmt =  connection.prepareStatement(sql);
     String senhaHash = HashUtil.gerarHash(usuario.getSenha());            
     
     
     
     stmt.setString(1, usuario.getNome());
     stmt.setString(2, usuario.getEmail());
     stmt.setString(3, senhaHash);
     stmt.setString(4, usuario.getCpf());
     stmt.execute();
     stmt.close();
    }catch (SQLException u) {
    throw new Exception("Erro ao inserir user");
    }
    }


  public usuario verificarLogin(String email, String senha) {
    this.connection = new ConnectionFactory().getConnection();
    String sql = "SELECT * FROM usuario WHERE email = ? AND senha = ?";

    try {
        PreparedStatement stmt = connection.prepareStatement(sql);
        
        String senhaHash = HashUtil.gerarHash(senha);            
        stmt.setString(1, email);
        stmt.setString(2, senhaHash); // compara com senha criptografada
        
        ResultSet rs = stmt.executeQuery();

        if (rs.next()) {
            usuario u = new usuario(); // Corrigido nome da classe
            int id = rs.getInt("id");
            String emailusuario = rs.getString("email");
            String adminVerificar = rs.getString("verificar_admin");

            u.setId(id);
            u.setEmail(emailusuario);
            u.setAdmin("S".equalsIgnoreCase(adminVerificar));

            sessao.setIdUsuario(id);  // Corrigido: Sessao com letra maiúscula
            sessao.setEmail(emailusuario);

            rs.close();
            stmt.close();
            return u; // retorna o usuário autenticado
        }

        rs.close();
        stmt.close();

    } catch (Exception e) {
        e.printStackTrace();
    }

    return null; // retorno seguro em caso de falha
}
     public usuario buscarUsuarioPorID(String id) throws SQLException {
        String sql = "SELECT * FROM usuario WHERE id LIKE ?";
        usuario usuario = null;

        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setString(1, "%" + id + "%");  // Usando LIKE para buscar por nome
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
           usuario = new usuario();
           
           
           usuario.setId(rs.getInt("id"));
           usuario.setNome(rs.getString("nome"));
           usuario.setEmail(rs.getString("email"));
           usuario.setCpf(rs.getString("cpf"));
           usuario.setAdmin("S".equalsIgnoreCase(rs.getString("verificar_admin"))
                );
            }
        }
        return usuario;
    }
    public void atualizarUsuario(usuario usuario) throws SQLException {
        String sql = "UPDATE usuario SET nome = ?, email = ?, cpf = ? WHERE id = ?";

        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setString(1, usuario.getNome());
            stmt.setString(2, usuario.getEmail());
            stmt.setString(3, usuario.getCpf());
            stmt.setInt(4, usuario.getId());
            stmt.executeUpdate();
        }
    }

    // Método para excluir um produto
    public void excluirUsuario(int id) throws SQLException {
        String sql = "DELETE FROM usuario WHERE id = ?";

        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setInt(1, id);
            stmt.executeUpdate();
        }
    }     
  
    
    
}
