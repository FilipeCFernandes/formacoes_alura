package br.com.alura.screenmatch.principal;
import br.com.alura.screenmatch.modelos.Titulo;
import com.google.gson.Gson;

import java.net.URI;
import java.net.http.HttpResponse.BodyHandlers;
import java.net.http.HttpResponse;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.util.Scanner;

public class PrincipalComBusca {
    public static void main(String[] args) throws java.io.IOException, InterruptedException {
        Scanner leitura = new Scanner(System.in);
        System.out.println("Digite um filme para busca: ");
        //String busca = new String();
        //busca = leitura.nextLine();

        String busca = leitura.nextLine();

        String endereco = "http://www.omdbapi.com/?t=" + busca.replace(" ", "+") + "&apikey=320bbb22";
        System.out.println(endereco);
        try {
            HttpClient client = HttpClient.newHttpClient();

            HttpRequest request = HttpRequest.newBuilder()
                    .uri(URI.create(endereco))
                    .build();

            HttpResponse<String> response = client
                    .send(request, BodyHandlers.ofString());
            System.out.println(response.body());
            Gson gson = new Gson();
            Titulo meuTitulo = new Titulo();

            gson.fromJson(response.body(), Titulo.class);
        }
    }
}
