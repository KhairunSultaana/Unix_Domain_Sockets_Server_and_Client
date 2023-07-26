SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(SERVER): server.cpp
    g++ -o $(SERVER) server.cpp

$(CLIENT): client.cpp
    g++ -o $(CLIENT) client.cpp

clean:
    rm -f $(SERVER) $(CLIENT)
