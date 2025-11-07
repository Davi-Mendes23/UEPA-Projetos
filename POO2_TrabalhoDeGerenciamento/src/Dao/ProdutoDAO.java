package Dao;

import modelo.Produto;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import factory.ConnectionFactory;

public class ProdutoDAO {
    private Connection connection;

    // Construtor, utilizando a ConnectionFactory para obter a conexão com o banco
    public ProdutoDAO() {
        this.connection = new ConnectionFactory().getConnection();
    }

    // Método para cadastrar um produto
    public void cadastrarProduto(Produto produto) throws SQLException {
        String sql = "INSERT INTO produtos (nome_produto, descricao, quantidade_produtos, procedencia) VALUES (?, ?, ?, ?)";

        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setString(1, produto.getNomeProduto());
            stmt.setString(2, produto.getDescricao());
            stmt.setInt(3, produto.getQuantidadeProdutos());
            stmt.setString(4, produto.getProcedencia());
            stmt.executeUpdate();
        }
    }

    // Método para buscar um produto pelo nome
    public Produto buscarProdutoPorNome(String nome) throws SQLException {
        String sql = "SELECT * FROM produtos WHERE nome_produto LIKE ?";
        Produto produto = null;

        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setString(1, "%" + nome + "%");  // Usando LIKE para buscar por nome
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                produto = new Produto(
                        rs.getInt("id"),
                        rs.getString("nome_produto"),
                        rs.getString("descricao"),
                        rs.getInt("quantidade_produtos"),
                        rs.getString("procedencia")
                );
            }
        }
        return produto;
    }

    // Método para atualizar as informações de um produto
    public void atualizarProduto(Produto produto) throws SQLException {
        String sql = "UPDATE produtos SET nome_produto = ?, descricao = ?, quantidade_produtos = ?, procedencia = ? WHERE id = ?";

        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setString(1, produto.getNomeProduto());
            stmt.setString(2, produto.getDescricao());
            stmt.setInt(3, produto.getQuantidadeProdutos());
            stmt.setString(4, produto.getProcedencia());
            stmt.setInt(5, produto.getId());
            stmt.executeUpdate();
        }
    }

    // Método para excluir um produto
    public void excluirProduto(int id) throws SQLException {
        String sql = "DELETE FROM produtos WHERE id = ?";

        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setInt(1, id);
            stmt.executeUpdate();
        }
    }

    // Método para buscar todos os produtos
    public List<Produto> buscarTodosProdutos() throws SQLException {
        List<Produto> listaProdutos = new ArrayList<>();
        String sql = "SELECT * FROM produtos";
        
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            ResultSet rs = stmt.executeQuery();
            
            // Preencher a lista com os produtos recuperados
            while (rs.next()) {
                Produto produto = new Produto(
                        rs.getInt("id"),
                        rs.getString("nome_produto"),
                        rs.getString("descricao"),
                        rs.getInt("quantidade_produtos"),
                        rs.getString("procedencia")
                );
                listaProdutos.add(produto);
            }
        }
        return listaProdutos;
    }
}
