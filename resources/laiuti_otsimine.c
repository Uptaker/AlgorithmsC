#include<stdio.h>

#include<conio.h>

int a[20][20], queue[20], label[20], prev[20] visited[20], n, i, j, f = 0, r = -1; // 20 on siin praegu kõigi tippude arv, ehk need massiivid on tehtud arvestusega, et iga tipu jaoks on üks lahter ... aga see eeldab, et igal tipul on vasteks indeks
// edasi tekib küsimus, et millised andmetüübid oleksid nüüd kasutatavas keeles käepärast?
void bfs(int v) {
	while järjekord ei ole tühi /* - kas kasutatavas keeles on äkki olemas queue andmestruktuur?? Seda oleks väga mõnus kasutada, lisaks võib selle tsükli lõpetada, 
	kui oled lõpptipule otsa komistanud.*/
	    võtan tipu järjekorrast - see on v
		for(i = 1; i <= n; i++)				//vaatan läbi kõik tipud ehk siis otsin üles kõik naabrid ja teen nendega järgmist (saab siis connections tabelist)
			if(a[v][i]==1 && !visited[i]) // kui on v-le naaber ja ei ole juba külastatud,
				queue[++r] = i;				// siis panen naabri järjekorra lõppu
				label[i] = label[v] + 1;	// tipu i kaugus alguspunktist on uuritava tipu v kaugus + 1
				prev[i] = v;				// tippu i tulin tipust v
		visited[v] = 1;						// märgin ennist järjekorrast võetud tipu külastatuks
	}

}

void main() {
int v;
printf("Enter the number of vertices: ");
scanf("%d",&n);
// Algväärtustamised 
for(i=1; i <= n; i++) {
	queue[i] = 0;
	label[i] = 0;
	prev[i] = -1;
	visited[i] = 0;
}

printf("\nEnter graph data in matrix form:\n");
for(i=1; i<=n; i++) {
	for(j=1;j<=n;j++) {
		scanf("%d", &a[i][j]);
	}
}

printf("Enter the starting vertex: ");
scanf("%d", &v);
queue[++r] = v;   // panen esimese tipu järjekorda, et sealt siis edasi juba tippe võtta ...
bfs(v);
printf("\nThe node which are reachable are:");
for(i=1; i <= n; i++) {
	if(visited[i])
		printf(" %d", i);
	else {
		printf("\nBFS is not possible. All nodes are not reachable!");
		break;
	}
}
getch();

}
