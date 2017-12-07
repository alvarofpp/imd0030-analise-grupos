SRC_DIR = src
INC_DIR = include
OBJ_DIR = build
LIB_DIR = lib
APP_DIR = application

CC = g++
CFLAGS = -O3 -Wall -std=c++11 -pedantic -I. -I$(INC_DIR)
ARCHIVE = ar

linux: agrupamento.a agrupamento.so prog_estatico prog_dinamico

agrupamento.a: $(SRC_DIR)/AlgoritmoHierarquico.Algorithm.cpp $(SRC_DIR)/AlgoritmoHierarquico.Construct.cpp $(SRC_DIR)/AlgoritmoHierarquico.Display.cpp $(SRC_DIR)/conjuntos.cpp $(SRC_DIR)/dados.cpp $(SRC_DIR)/dataframe.cpp $(INC_DIR)/algoritmo_hierarquico.h $(INC_DIR)/conjuntos.h $(INC_DIR)/dados.h $(INC_DIR)/dataframe.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/AlgoritmoHierarquico.Algorithm.cpp -o $(OBJ_DIR)/AlgoritmoHierarquico.Algorithm.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/AlgoritmoHierarquico.Construct.cpp -o $(OBJ_DIR)/AlgoritmoHierarquico.Construct.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/AlgoritmoHierarquico.Display.cpp -o $(OBJ_DIR)/AlgoritmoHierarquico.Display.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/conjuntos.cpp -o $(OBJ_DIR)/conjuntos.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/dados.cpp -o $(OBJ_DIR)/dados.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/dataframe.cpp -o $(OBJ_DIR)/dataframe.o
	$(AR) rcs $(LIB_DIR)/$@ $(OBJ_DIR)/AlgoritmoHierarquico.Algorithm.o $(OBJ_DIR)/AlgoritmoHierarquico.Construct.o $(OBJ_DIR)/AlgoritmoHierarquico.Display.o $(OBJ_DIR)/conjuntos.o $(OBJ_DIR)/dados.o $(OBJ_DIR)/dataframe.o
	@echo "+++ [Biblioteca estatica criada em $(LIB_DIR)/ $@] +++"

agrupamento.so: $(SRC_DIR)/AlgoritmoHierarquico.Algorithm.cpp $(SRC_DIR)/AlgoritmoHierarquico.Construct.cpp $(SRC_DIR)/AlgoritmoHierarquico.Display.cpp $(SRC_DIR)/conjuntos.cpp $(SRC_DIR)/dados.cpp $(SRC_DIR)/dataframe.cpp $(INC_DIR)/algoritmo_hierarquico.h $(INC_DIR)/conjuntos.h $(INC_DIR)/dados.h $(INC_DIR)/dataframe.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/AlgoritmoHierarquico.Algorithm.cpp -o $(OBJ_DIR)/AlgoritmoHierarquico.Algorithm.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/AlgoritmoHierarquico.Construct.cpp -o $(OBJ_DIR)/AlgoritmoHierarquico.Construct.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/AlgoritmoHierarquico.Display.cpp -o $(OBJ_DIR)/AlgoritmoHierarquico.Display.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/conjuntos.cpp -o $(OBJ_DIR)/conjuntos.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/dados.cpp -o $(OBJ_DIR)/dados.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/dataframe.cpp -o $(OBJ_DIR)/dataframe.o
	$(CC) -shared -fPIC -o $(LIB_DIR)/$@ $(OBJ_DIR)/AlgoritmoHierarquico.Algorithm.o $(OBJ_DIR)/AlgoritmoHierarquico.Construct.o $(OBJ_DIR)/AlgoritmoHierarquico.Display.o $(OBJ_DIR)/conjuntos.o $(OBJ_DIR)/dados.o $(OBJ_DIR)/dataframe.o 
	@echo "+++ [Biblioteca estatica criada em $(LIB_DIR)/ $@] +++"

prog_estatico:
	$(CC) $(CFLAGS) $(APP_DIR)/agrupamento.cpp $(LIB_DIR)/agrupamento.a -o $(OBJ_DIR)/$@

prog_dinamico:
	$(CC) $(CFLAGS) $(APP_DIR)/agrupamento.cpp	$(LIB_DIR)/agrupamento.so -o $(OBJ_DIR)/$@

clean:
	@echo "Removendo arquivos objetos e executaveis/binarios..."
	rm -f $(OBJ_DIR)
