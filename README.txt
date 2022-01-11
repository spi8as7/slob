Project 3 OS
===========================================================
Dimitrios Greasidis 	AEM : 1624  EMAIL : greasidi@uth.gr
Stefanos Papanastasiou 	AEM : 1608  EMAIL : stepapan@uth.gr
===========================================================

Gia to zitoumeno tis ergasias, pou itan i antikatastasi twn algorithmwn next-fit kai first-fit twn sinartisewn slob_alloc kai slob_page_alloc antistoixa me ton algorithmo best-fit, egine xrisi tis #ifdef wste analogws to define na dokimazoume ton algorithmo pou dimiourgisame i na trexoume ton idi uparxonta gia na sigkrinoume ta apotelesmata. To zitoume ilopoihthike stis sinartiseis slob_page_alloc kai slob_alloc. Xrisimopoihthikan kapoies global metavlites px flag gia ta prints.

I efarmogi pou dimiourgisame kali 7 fores ta syscalls ektupwnwntas ta apotelesmata opote dinoume ena xaraktira, wste an theloume na anoigoume kapoia programmata kai na vlepoume ta apotelesmata.

Sas stelnoume 4 arxeia pou periexoun ta apotelesmata tis efarmogis pou dimiourgisame apo to treximo twn algorithwn, first-fit k best-fit. Kanonika tha eprepe na einai duo, alla eksaitias tou provlimatos pou antimetwpisame me to busy box pou bootari sto shell otan exoume k ta duo syscalls energopoihmena, treksame t kathe syscall ksexwrista gia tous algorithmous first-fit k best-fit. Ta arxeia periexontai sto fakelo statistics. Apo ta apotelesmata tis efarmogis vlepoume pws i best fit desmeuei kata meso oro kalutero pososto mnimis(mikrotero) apo tin first fit kai auto ginetai eksaitias tou algorithmou kathws psaxnei gia to mikrotero dunato block. Akoma vlepoume pws i eleutheri mnimi einai perrisoteri ston best-fit kathws den desmeuoume megala blocks kai aksiopoioume kalutera ti mnimi se antithesi me tin first fit.

Opws paratiroume i best-fit meiwnei ton ekswteriko katakermatismo kathws menei ligoteri eleutheri mnimi axrisimopoihth, ara aksiopoihtai kalutera i mnimi.

Otan allaksame to slob.c sto directory ../mm kaname cd .. kai metaglwtisame k egkatastisame ton neo pirina me tis eksis entoles:
	sudo make
	sudo make modules_install
	sudo make install

Episis ta syscalls prostethikan sto telos tou arxeiou slob.c kathws k mia sinartisi "long sum_free_mem(struct list_head *slob_list)" i opoia vriskei ton eleuthero xwro kai kaleitai apo ta syscalls. Gia na doulepsoun auta ta syscalls dilwsame ta protupa opws anaferetai ston odigo gia ta syscalls kathws kai valame sto Makefile tou antistixou directory tou slob.c stin grammi obj-y = ..... slob.o wste na leifthei k auto to arxeio upopsin gia ta syscalls kata tin metaglwtisi tou pirina.

I efarmogi epipedou xristi exei onoma test_statistics.c omws eksaitias tou provlimatos pou anaferame parapanw ftiaksame duo alles efarmoges mia gia tin ektupwsi tou free_mem kai mia gia tou allocated_mem me onomata  statistics_free_mem.c kai statistics_alloc_mem.c antistoixa. Episinaptoume k tis 3 efarmoges.
	metaglwtisi : gcc -g -Wall test_statistics.c

I Best-fit paratiroume oti einai simantika pio argi kathws kathe fora pou erxetai ena request prepei na vrei to kalutero block k tin kaluteri selida wste na desmeusei tin mnimi pou zititai, kati to opoio einai arketa xronovoro. Antitheta i first-fit desmeumei to prwto block pou vriskei k ikanopoiei tis apaitiseis tou aitimatos kai gia auto to logo einai emfanws grigoroteri.

Ena stigmiotupo twn apotelesmatwn trexwntas ton algorithmo Best-fit einai:

[	15.020491] slob_Request: BEST FIT 1096
[	15.020493] slob_alloc: BEST FIT Candidate blocks size: 1392
slob_alloc: BEST FIT : 1392


[	15.200706] slob_Request: BEST FIT 40
[	15.200708] slob_alloc: BEST FIT Candidate blocks size: 0 4 4 0 0 0 0 0 0 0 0 0 0 0 0 4 0 0 0 4 0 0 44 0 0 0 0 0 0
slob_alloc: BEST FIT : 44

[	15.380451] slob_Request: BEST FIT 28
[	15.380454] slob_alloc: BEST FIT Candidate blocks size: 24 0 24 0 24 0 4 0 24 0 16 0 28 0 24 0 24 0 24 0 96 8
slob_alloc: BEST FIT : 28

[	15.479524] slob_Request: BEST FIT 72
[	15.479529] slob_alloc: BEST FIT Candidate blocks size: 72 1912
slob_alloc: BEST FIT : 72

Opws vlepoume o algorithmos douleuei opws tha eprepe kathws desmeuei to block pou tairiazei kalutera se sxesi me to request.


