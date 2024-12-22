public static void main (String [] args){
    int i, Fat = 4;
    for (i = 1; i <= Fat; i++){
        Fat = Fat*i;
    }
    System.out.print(Fat);
}

package br.com.alura.screenmatch.modelos;

public class Serie extends Titulo{
    int temporadas;
    int episodiosPorTemporada;
    boolean ativa;
    int minutosPorEpisodio;

    public int getTemporadas() {
        return temporadas;
    }

    public void setTemporadas(int temporadas) {
        this.temporadas = temporadas;
    }

    public int getEpisodiosPorTemporada() {
        return episodiosPorTemporada;
    }

    public void setEpisodiosPorTemporada(int episodiosPorTemporada) {
        this.episodiosPorTemporada = episodiosPorTemporada;
    }

    public boolean isAtiva() {
        return ativa;
    }

    public void setAtiva(boolean ativa) {
        this.ativa = ativa;
    }

    public int getMinutosPorEpisodio() {
        return minutosPorEpisodio;
    }

    public void setMinutosPorEpisodio(int minutosPorEpisodio) {
        this.minutosPorEpisodio = minutosPorEpisodio;
    }

    @Override
    public int getDuracaoEmMinutos() {
        return minutosPorEpisodio * episodiosPorTemporada * temporadas;
    }
}
