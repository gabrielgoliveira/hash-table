int hashing(int chave, int table_size){
    int num_bits, parte1, parte2;
    num_bits = 10;
	parte1 = chave >> num_bits;
	parte2 = chave & (table_size-1);
	return (parte1 ^ parte2);
}
