from django.db import models

class Fotografia(models.Model):
    OPCOES_CHOICES = [
        ('NEBULOSA', 'Nebulosa'),
        ('ESTRELA', 'Estrela'),
        ('GALÁXIAS', 'Galáxias'),
        ('PLANETA', 'Planeta'),
    ]
    categoria = models.CharField(max_length=100, choices=OPCOES_CHOICES, default='')
    nome = models.CharField(max_length=100, null=False, blank=False)
    legenda = models.CharField(max_length=150, null=False, blank=False)
    descricao = models.TextField(null=False, blank=False)
    foto = models.CharField(max_length=100, null=False, blank=False)

    def __str__(self):
        return f"Fotografia [nome: {self.nome}]"
    
    def set_foto(self, valor):
        self.foto = valor