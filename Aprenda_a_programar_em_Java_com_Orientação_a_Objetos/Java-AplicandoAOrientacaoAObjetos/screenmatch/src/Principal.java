import br.com.alura.screenmatch.modelos.Filme;
import br.com.alura.screenmatch.modelos.Serie;

public class Principal {
    public static void main(String[] args) {
        Filme meuFilme = new Filme();
        meuFilme.setNome("O poderoso chefão");
        meuFilme.setAnoDeLancamento(1970);
        meuFilme.setDuracaoEmMinutos(180);

//        System.out.println(meuFilme.nome);
        meuFilme.exibeFicahTecnica();
        meuFilme.avalia(8);
        meuFilme.avalia(5);
        meuFilme.avalia(10);
//        System.out.println(meuFilme.somaDasAvaliacoes);
//        System.out.println(meuFilme.totalDeAvaliacao);
        System.out.println(meuFilme.pegaMedia());
        Serie lost = new Serie();
        lost.setNome("Lost");
        lost.setTemporadas(10);
        lost.setAnoDeLancamento(2000);
        lost.exibeFicahTecnica();
        lost.setEpisodiosPorTemporada(10);

        lost.setMinutosPorEpisodio(50);
        System.out.println("Tempo, em minutos, para maratonar Lost: " + lost.getDuracaoEmMinutos() + "min");
    }
}