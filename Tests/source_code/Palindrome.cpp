int main() {
	char str[100];
	int flag = 0;
	int length = 0;
	scanf("%s", str);
	while(str[length] != '\0') length++;
	for (int i = 0; i < length / 2; i++) {
		if (str[i] != str[length - i - 1])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0){
		printf("yes\n");
	} else {
		printf("no\n");
	}
	return 0;
}