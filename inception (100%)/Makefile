all: build run

data:
	@if [ ! -d "home/bdenfir/data/mariadb" ] && [ ! -d "home/bdenfir/data/wordpress;" ]; then \
	mkdir -p home/bdenfir/data/mariadb && mkdir -p home/bdenfir/data/wordpress; fi

build: data
	docker compose -f srcs/docker-compose.yml build

run:
	docker compose -f srcs/docker-compose.yml up -d

down:
	docker compose -f srcs/docker-compose.yml down

clean:
	docker compose -f srcs/docker-compose.yml down --rmi all

vclean:
	docker compose -f srcs/docker-compose.yml down --rmi all -v
	@sudo rm -rf home

fclean: vclean
	docker system prune -af

list:
	docker ps -a

volumes:
	docker volume ls

images:
	docker image ls

network:
	docker network ls

full: list volumes images network

.SILENT:
