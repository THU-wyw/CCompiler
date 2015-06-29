void getString(char[] buffer) {
	int i = 0;
	scanf("%s", buffer);
	while (buffer[i] != 0 && buffer[i] != 10 && buffer[i] != 13) i++;
	buffer[i] = 0;
}