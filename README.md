## Lexer

Inside the working directory run:
```
$ docker build -t compiler .
$ docker run -it -v $(pwd):/compiler compiler
$ bash run.sh ./tests/<test_file_name>
```