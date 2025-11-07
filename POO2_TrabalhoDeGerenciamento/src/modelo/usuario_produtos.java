/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package modelo;

/**
 *
 * @author icegurto
 */
public class usuario_produtos {
    int id_usuario;
    int id_produtos;
    int quantidade_comprada;
    String log;
    String movimentacao;

    public int getId_usuario() {
        return id_usuario;
    }

    public int getId_produtos() {
        return id_produtos;
    }

    public int getQuantidade_comprada() {
        return quantidade_comprada;
    }

    public String getLog() {
        return log;
    }

    public String getMovimentacao() {
        return movimentacao;
    }

    public void setId_usuario(int id_usuario) {
        this.id_usuario = id_usuario;
    }

    public void setId_produtos(int id_produtos) {
        this.id_produtos = id_produtos;
    }

    public void setQuantidade_comprada(int quantidade_comprada) {
        this.quantidade_comprada = quantidade_comprada;
    }

    public void setLog(String log) {
        this.log = log;
    }

    public void setMovimentacao(String movimentacao) {
        this.movimentacao = movimentacao;
    }
    
}
