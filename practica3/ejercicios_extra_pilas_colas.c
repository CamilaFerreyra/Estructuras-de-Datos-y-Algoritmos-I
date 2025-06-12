#include "pila.h"
#include <string.h>

static void imprimir_entero(int x) {
    printf("%d ", x);
}

static void imprimir_caracter(int x) {
    printf("%c ", x);
}

int es_operador(char op) {
    return (op == '+' ||
                op == '-' ||
                    op == '*' ||
                        op == '/');
}

int operar(char operador, int operando1, int operando2) {
    switch(operador) {
        case '+':
            return operando2 + operando1;
        case '-':
            return operando2 - operando1;
        case '*':
            return operando2 * operando1;
        case '/':
            return operando1 != 0 ? operando2 / operando1 : 0;
    }
}

// Asumimos operaciones binarias
int resolver_parentesis(Pila operandos, Pila operadores) {
    int a = pila_tope(operandos);
    pila_desapilar(operandos);
    int b = pila_tope(operandos);
    pila_desapilar(operandos);
    char op = pila_tope(operadores);
    pila_desapilar(operadores);

    int resultado = operar(op, a, b);
    pila_apilar(operandos, resultado);
}

void agregar_simbolo(Pila operadores, Pila operandos, char simbolo) {
    if(es_operador(simbolo))
        pila_apilar(operadores, simbolo);
    else if(simbolo == ')') {
        resolver_parentesis(operandos, operadores);
    } else if(simbolo != '(') {
        // Asumimos números de 1 digito
        int operando = simbolo - '0';
        pila_apilar(operandos, operando);
    }
}

int eval(char *expr) {
    Pila operandos = pila_crear();
    Pila operadores = pila_crear();

    int largo_expresion = strlen(expr);
    for(int i = 0; i < largo_expresion; i++){
        agregar_simbolo(operadores, operandos, expr[i]);
    }

    while(!pila_es_vacia(operadores))
        resolver_parentesis(operandos, operadores);

    int valor = pila_tope(operandos);
    pila_destruir(operandos);
    pila_destruir(operadores);
    return valor;
}

int main() {
    //char expr[] = "(5/(4-(3-(2-1))))";
    char expr[] = "(1+(2+3)*4*5)";
    printf("%d\n", eval(expr));
}