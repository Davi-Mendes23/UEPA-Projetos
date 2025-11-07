package relatorios;

//importar a biblioteca para gerar o pdf do alvarokkkkkk
import com.itextpdf.text.Document;
import com.itextpdf.text.Paragraph;
import com.itextpdf.text.pdf.PdfWriter;
import factory.ConnectionFactory;

import java.io.FileOutputStream;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;

public class RelatorioProdutos {

    public void gerarRelatorio() {
        Document documento = new Document();

        try {
            // Conexao
            Connection conn = new ConnectionFactory().getConnection();
            Statement stmt = conn.createStatement();

            // Substitui "produtos" pelo nome cdorreto pelo amor de deus caue
            ResultSet rs = stmt.executeQuery("SELECT * FROM produtos");

            // Cria o PDF no diretório do projeto
            PdfWriter.getInstance(documento, new FileOutputStream("Relatorio_Produtos.pdf"));
            documento.open();

            documento.add(new Paragraph("Relatório de Produtos"));
            documento.add(new Paragraph(" ")); //espaço

            // Enquanto houver produtos, adiciona ao PDF
            while (rs.next()) {
                documento.add(new Paragraph(
                    "id: " + rs.getInt("id") + "\n" +                           
                    "nome_produto: " + rs.getString("nome") + "\n" +                   
                    "descricao: R$" + rs.getDouble("descricao") + "\n" + 
                    "procedencia: " + rs.getString("procedencia") + "\n" +  
                    "quantidade_produtos: " + rs.getInt("quantidade_produtos") + "\n\n"         
                ));
            }

            documento.close();
            stmt.close();
            conn.close();

            System.out.println("Relatório gerado com sucesso!");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
