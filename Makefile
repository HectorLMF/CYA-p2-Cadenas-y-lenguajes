CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
SRCDIR = src
SOURCES = $(SRCDIR)/Alphabet.cc $(SRCDIR)/String.cc $(SRCDIR)/Language.cc $(SRCDIR)/Main.cc
HEADERS = $(SRCDIR)/Alphabet.h $(SRCDIR)/String.h $(SRCDIR)/Language.h
EXECUTABLE = cadenas_lenguajes

# Herramientas de formateo
CLANG_FORMAT = clang-format
FORMAT_STYLE = file

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(SOURCES)

clean:
	rm -f $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Formateo de código
format:
	@echo "Aplicando formato Google Style a todos los archivos..."
	@$(CLANG_FORMAT) -i -style=$(FORMAT_STYLE) $(SOURCES) $(HEADERS)
	@echo "Formato aplicado correctamente."

# Verificar formato sin modificar archivos
format-check:
	@echo "Verificando formato de código..."
	@$(CLANG_FORMAT) -style=$(FORMAT_STYLE) --dry-run --Werror $(SOURCES) $(HEADERS)

# Mostrar diferencias de formato
format-diff:
	@echo "Mostrando diferencias de formato..."
	@for file in $(SOURCES) $(HEADERS); do \
		echo "=== $$file ==="; \
		$(CLANG_FORMAT) -style=$(FORMAT_STYLE) $$file | diff -u $$file - || true; \
		echo ""; \
	done

# Compilar con formato automático
build: format $(EXECUTABLE)

# Target que aplica formato antes de cada compilación
auto-format: format
	$(MAKE) $(EXECUTABLE)

# Documentación con Doxygen
docs:
	@echo "Generando documentación con Doxygen..."
	@doxygen Doxyfile
	@echo "Documentación generada en docs/html/index.html"

# Limpiar documentación
clean-docs:
	@echo "Limpiando documentación..."
	@rm -rf docs/html docs/latex docs/xml docs/man docs/rtf
	@echo "Documentación eliminada."

# Ver documentación en navegador
view-docs: docs
	@echo "Abriendo documentación en el navegador..."
	@if command -v xdg-open > /dev/null; then \
		xdg-open docs/html/index.html; \
	elif command -v firefox > /dev/null; then \
		firefox docs/html/index.html; \
	elif command -v google-chrome > /dev/null; then \
		google-chrome docs/html/index.html; \
	else \
		echo "No se encontró un navegador web. Abra manualmente docs/html/index.html"; \
	fi

# Limpieza completa (ejecutable y documentación)
clean-all: clean clean-docs

.PHONY: all clean run format format-check format-diff build auto-format docs clean-docs view-docs clean-all