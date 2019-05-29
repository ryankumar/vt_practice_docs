void *Producer(void *arg) 
{
	int produced=0;
	int input = 0;
	cout << "\nProducer created.." << endl;
	while(!terminatethreads)      {
		sem_wait(Sempty);  //Decrements 'empty' 
		produced++;
		input = (input + 1) % BUFSIZE;
	//	sem_wait(Sflag);
		buf[input] = produced;
		mycount++;
	//	sem_post (Sflag);
		cout << "Producing  widget # " << produced << " in buffer # " << input << endl;
		sem_post(Sfull);//increments  full , tell consumer that it can consume now
	//	usleep(rand () %997);
		sleep(1);
	}
	
	pthread_exit(NULL);
	return &buf[0];
}
