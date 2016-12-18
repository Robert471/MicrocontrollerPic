switch(expresion)				-> Primero se evalua la expresion
{								   y en orden al caso adecuado
	case VAL1:					   para ejecutar la sentencia asociada.
		sentencia;				-> si ninguno de los CASE corresponde
		break;					   al VALOR se ejecuta DEFAULT(comando
								   opcional).	
	case VAL2:					-> El comando BREAK provoca la salida 
		sentencia;				   de SWITCH, caso contrario ejecuta
		break;					   el siguiente CASE.

		.....
	default:
		sentencia;
		break;
}

