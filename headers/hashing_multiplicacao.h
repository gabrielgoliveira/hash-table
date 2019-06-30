int hashing(int chave, int table_size){
    float A = 0.6180339887; //constante: 0 < A < 1 
	float val = chave * A;
	val = val - (int)val;
	return (int)(table_size * val);
}
