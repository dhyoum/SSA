	for (int i = 2; i< MAX_P; i++)
		prime[i] = i;
	for (int i = 2; i*i < MAX_P; i++) {
		if (prime[i] == 0) continue;
		for (int n=i+i; n < MAX_P; n+=i) {
			prime[n] = 0;
		}
	}
