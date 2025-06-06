all : up

up : 
	@docker-compose -f ./srcs/docker-compose.yml --env-file .env up -d

down : 
	@docker-compose -f ./srcs/docker-compose.yml --env-file .env down

stop : 
	@docker-compose -f ./srcs/docker-compose.yml --env-file .env stop

start : 
	@docker-compose -f ./srcs/docker-compose.yml --env-file .env start

status : 
	@docker ps