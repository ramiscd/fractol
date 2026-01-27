# fractol

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/5/5f/Julia-Set_z2%2Bc_ani.gif" alt="fractol preview" width="700px">
</p>

Um explorador visual de fractais em **C**, construído com a biblioteca gráfica **MiniLibX**.  
Explore conjuntos como **Mandelbrot** e **Julia** em tempo real com zoom, movimento e renderização suave.

---

## 🎯 Sobre o projeto

fractol é um programa que renderiza fractais matemáticos com gráficos interativos.  
Ele mapeia pontos do plano complexo para uma janela gráfica, traçando padrões infinitamente repetitivos e coloridos com base em relações iterativas.

Esse projeto explora:

- **Programação gráfica de baixo nível**
- **Operações com números complexos**
- **Manipulação de eventos (teclado/mouse)**
- **Otimizações de renderização e cores**

---

## 🛠️ Funcionalidades principais

- Renderização de fractais clássicos: **Mandelbrot**, **Julia**, etc. :contentReference[oaicite:2]{index=2}  
- Navegação com teclado e mouse  
- Zoom em tempo real  
- Paletas de cores customizáveis  
- Cálculo eficiente de escape time

---

## 🧩 Pré-requisitos

Antes de compilar, você precisa:

- Um compilador C (como `gcc` ou `clang`)
- Biblioteca **MiniLibX**
- Ferramentas básicas de build (`make`)

> Se estiver usando um ambiente *nix ou Linux, instale as dependências do MiniLibX e X11 antes de compilar.

---

## 📦 Instalação

```bash
git clone https://github.com/ramiscd/fractol.git
cd fractol
make
````

---

## ▶️ Como usar

```bash
./fractol <fractal> [opções]
```

Exemplos:

```bash
./fractol mandelbrot
./fractol julia -0.7 0.27015
```

---

## 🎮 Controles

| Ação                   | Entrada          |
| ---------------------- | ---------------- |
| Mover vista            | Direcionais      |
| Zoom                   | Scroll do mouse  |
| Reset                  | `R`              |
| Sair do programa       | `Esc`            |
| Mudar parâmetros Julia | Teclas dedicadas |

> Ajuste os valores de acordo com sua implementação real.

---

## 💡 Como funciona (visão técnica)

Cada pixel da janela representa um número complexo.
Para cada ponto `c`, o programa itera a fórmula:

```
zₙ₊₁ = zₙ² + c
```

Testando quantas iterações até `|z| > 2`, determinamos a cor do pixel.
Isso forma padrões infinitos e auto-semelhantes como o **Conjunto de Mandelbrot**. ([Wikipédia][2])

---

## 🧪 Exemplos de fractais suportados

* **Mandelbrot**
* **Julia**
* (adicione outros que você implementou)

---

## 📁 Estrutura do repositório

```
fractol/
├─ src/
├─ include/
├─ assets/
├─ Makefile
├─ fractol.h
└─ README.md
```

---

## 🙌 Contribuições

Contribuições são bem-vindas!
Abra issues ou pull requests para melhorias ou novas features.
