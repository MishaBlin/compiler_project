## Lexer

Inside the working directory run:
```
$ docker build -t compiler .
$ docker run -it -v $(pwd):/app my-lexer-app
$ ./run.sh <test_file_name>
```