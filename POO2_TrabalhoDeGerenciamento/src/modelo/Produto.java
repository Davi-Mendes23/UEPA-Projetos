package modelo;

public class Produto {
    private int id;
    private String nomeProduto;
    private String descricao;
    private int quantidadeProdutos;
    private String procedencia;

    // Construtor
    public Produto(int id, String nomeProduto, String descricao, int quantidadeProdutos, String procedencia) {
        this.id = id;
        this.nomeProduto = nomeProduto;
        this.descricao = descricao;
        this.quantidadeProdutos = quantidadeProdutos;
        this.procedencia = procedencia;
    }

    // Getters e Setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNomeProduto() {
        return nomeProduto;
    }

    public void setNomeProduto(String nomeProduto) {
        this.nomeProduto = nomeProduto;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public int getQuantidadeProdutos() {
        return quantidadeProdutos;
    }

    public void setQuantidadeProdutos(int quantidadeProdutos) {
        this.quantidadeProdutos = quantidadeProdutos;
    }

    public String getProcedencia() {
        return procedencia;
    }

    public void setProcedencia(String procedencia) {
        this.procedencia = procedencia;
    }
}
