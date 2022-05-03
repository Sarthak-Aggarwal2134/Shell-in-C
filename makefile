all:
	gcc allheaders.h jobs.c bg.c fg.c sigg.c overkill.c piping.c redirection.c shell.c display.c input.c echo.c cd.c pwd.c ls.c repeat.c pinfo.c sys_cmd.c history.c exec.c signal.c -o shell
compile:
