from sklearn.feature_extraction.text import CountVectorizer
import pandas as pd
from sklearn.metrics.pairwise import cosine_similarity
import ply.lex as lex
import numpy as np
from sklearn.metrics import jaccard_score

from Bio.pairwise2 import format_alignment
from Bio import pairwise2
import string

reservada = (
    # Palabras Reservadas
    'INCLUDE',
    'USING',
    'NAMESPACE',
    'STD',
    'COUT',
    'CIN',
   'GET',
   'CADENA',
  'RETURN',
   'VOID',
    'INT',
    'ENDL',
)
tokens = reservada + (
    'IDENTIFICADOR',
    'ENTERO',
    'ASIGNAR',

    'SUMA',
    'RESTA',
    'MULT',
    'DIV',
    'POTENCIA',
    'MODULO',

   'MINUSMINUS',
   'PLUSPLUS',

    #Condiones
   'SI',
    'SINO',
    #Ciclos
   'MIENTRAS',
   'PARA',
    #logica
    'AND',
    'OR',
    'NOT',
    'MENORQUE',
    'MENORIGUAL',
    'MAYORQUE',
    'MAYORIGUAL',
    'IGUAL',
    'DISTINTO',
    # Symbolos
    'NUMERAL',

    'PARIZQ',
    'PARDER',
    'CORIZQ',
    'CORDER',
    'LLAIZQ',
    'LLADER',
    
    # Otros
    'PUNTOCOMA',
    'COMA',
    'COMDOB',
    'MAYORDER', #>>
    'MAYORIZQ', #<<
)

# Reglas de Expresiones Regualres para token de Contexto simple

t_SUMA = r'\+'
t_RESTA = r'-'
t_MINUSMINUS = r'\-\-'
# t_PUNTO = r'\.'
t_MULT = r'\*'
t_DIV = r'/'
t_MODULO = r'\%'
t_POTENCIA = r'(\*{2} | \^)'

t_ASIGNAR = r'='
# Expresiones Logicas
t_AND = r'\&\&'
t_OR = r'\|{2}'
t_NOT = r'\!'
t_MENORQUE = r'<'
t_MAYORQUE = r'>'
t_PUNTOCOMA = ';'
t_COMA = r','
t_PARIZQ = r'\('
t_PARDER = r'\)'
t_CORIZQ = r'\['
t_CORDER = r'\]'
t_LLAIZQ = r'{'
t_LLADER = r'}'
t_COMDOB = r'\"'



def t_INCLUDE(t):
    r'include'
    return t

def t_USING(t):
    r'using'
    return t

def t_NAMESPACE(t):
    r'namespace'
    return t

def t_STD(t):
    r'std'
    return t

def t_COUT(t):
    r'cout'
    return t

def t_CIN(t):
    r'cin'
    return t

def t_GET(t):
    r'get'
    return t

def t_ENDL(t):
    r'endl'
    return t

def t_SINO(t):
    r'else'
    return t

def t_SI(t):
    r'if'
    return t

def t_RETURN(t):
   r'return'
   return t

def t_VOID(t):
   r'void'
   return t

def t_MIENTRAS(t):
    r'while'
    return t

def t_PARA(t):
    r'for'
    return t

def t_ENTERO(t):
    r'\d+'
    t.value = int(t.value)
    return t

def t_IDENTIFICADOR(t):
    r'\w+(_\d\w)*'
    return t

def t_CADENA(t):
   r'\"?(\w+ \ *\w*\d* \ *)\"?'
   return t

def t_NUMERAL(t):
    r'\#'
    return t

def t_PLUSPLUS(t):
    r'\+\+'
    return t

def t_MENORIGUAL(t):
    r'<='
    return t

def t_MAYORIGUAL(t):
    r'>='
    return t

def t_IGUAL(t):
    r'=='
    return t

def t_MAYORDER(t):
    r'<<'
    return t

def t_MAYORIZQ(t):
    r'>>'
    return t

def t_DISTINTO(t):
    r'!='
    return t

def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

def t_comments(t):
    r'/\*(.|\n)*?\*/'
    t.lexer.lineno += t.value.count('\n')
    print("Comentario de multiple linea")

def t_comments_ONELine(t):
     r'\/\/(.)*\n'
     t.lexer.lineno += 1
     print("Comentario de una linea")
t_ignore =' \t'

def t_error( t):
    #global resultado_lexema
    resultado_lexema = []
    estado = "** Token no valido en la Linea {:4} Valor {:16} Posicion {:4}".format(str(t.lineno), str(t.value),
                                                                      str(t.lexpos))
    resultado_lexema.append(estado)
    t.lexer.skip(1)
def listToString(s): 
    
    # initialize an empty string
    str1 = " " 
    
    # return string  
    return (str1.join(s))
# Prueba de ingreso
def prueba(data):
    #global resultado_lexema
    resultado_lexema = []

    analizador = lex.lex()
    analizador.input(data)

    resultado_lexema.clear()
    while True:
        tok = analizador.token()
        if not tok:
            break
        # print("lexema de "+tok.type+" valor "+tok.value+" linea "tok.lineno)
        #estado = "Linea {:4} Tipo {:16} Valor {:16} Posicion {:4}".format(str(tok.lineno),str(tok.type) ,str(tok.value), str(tok.lexpos) )
        estado = str(tok.type)
        resultado_lexema.append(estado)
    return resultado_lexema

 # instanciamos el analizador lexico
def jaccard(a, b):
    c = a.intersection(b)
    return float(len(c)) / (len(a) + len(b) - len(c))

def Convert(string):
    li = list(string.split(" "))
    return li

def Convert2(string):
    list1=[]
    list1[:0]=string
    return list1

def cambio(a,elemento,canje):
  return [canje if x==elemento else x for x in a]
  #return [canje if x==elemento else x for x in a]
#cambio(a,'#','A')
def listToString(s): 
    # initialize an empty string
    str1 = "" 
    
    # traverse in the string  
    for ele in s: 
        str1 += ele  
    
    # return string  
    return str1 
def listToString2(s): 
    
    # initialize an empty string
    str1 = ''
    
    # return string  
    return (str1.join(s))
analizador = lex.lex()

if __name__ == '__main__':
    f1=open("file1.cpp","r")
    f2=open("file2.cpp","r")
    data1 = f1.read()
    data2 = f2.read()
#    data = input("ingrese: ")
    r1=prueba(data1)
    r2=prueba(data2)
    r1.append('#')
    r3=r1+r2
    print(r1,"\n")
    print(r2,"\n")
    print(r3,"\n")
    #print(resultado_lexema)

    canjes=Convert2(string.ascii_uppercase+string.ascii_lowercase)
    a=r3
    init=0
    for i in range(init,len(a)):
        #for j in range(0,len(a)):
        if (len(a[i])>1):
            a=cambio(a,a[i],canjes[init])
            init=init+1

    print(a,'\n')

    division=a.index('#')

    code1=listToString2(a[0:division])
    code2=listToString2(a[division+1:])

    print(len(code2))

    #for a in pairwise2.align.localxx(code1, code2):
        #print(format_alignment(*a))
    for a in pairwise2.align.globalms(code2, code1, 2, -1,-1,-1):
        print(format_alignment(*a))
    print(a[2:])

    score=int(a[2])
    similitud=score*100.0/(max(len(code1),len(code2)))
    print(similitud)