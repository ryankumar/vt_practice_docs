void *Consumer(void *arg)    
{
	int  consumed= 0;
	cout << "\nConsumer created.." << endl;
	while(!terminatethreads)     {
		sem_wait(Sfull);
		consumed = (consumed + 1) % BUFSIZE;
//		sem_wait(Sflag);
		mycount--;
//		sem_post(Sflag);
		cout << "Consuming widget # " << buf[consumed] << " in buffer # " << consumed << endl;
		sem_post(Sempty);
//		usleep(rand () %1003);
		sleep(1);
	}
	pthread_exit(NULL);
	return &buf[0];

}

