.PHONY: build-client build-server build

build-client:
	gcc -o ./build/tcp_client ./tcp_client/main.c

build-server:
	gcc -o ./build/tcp_server ./tcp_server/main.c

build: build-client build-server

run-client: build-client
	./build/client

run-server: build-server
	./build/tcp_server
