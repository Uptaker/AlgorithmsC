#include<stdio.h>

#include<conio.h>

int a[20][20], queue[20], label[20], prev[20] visited[20], n, i, j, f = 0, r = -1; // 20 on siin praegu k�igi tippude arv, ehk need massiivid on tehtud arvestusega, et iga tipu jaoks on �ks lahter ... aga see eeldab, et igal tipul on vasteks indeks
// edasi tekib k�simus, et millised andmet��bid oleksid n��d kasutatavas keeles k�ep�rast?
void bfs(int v) {
	while j�rjekord ei ole t�hi /* - kas kasutatavas keeles on �kki olemas queue andmestruktuur?? Seda oleks v�ga m�nus kasutada, lisaks v�ib selle ts�kli l�petada, 
	kui oled l�pptipule otsa komistanud.*/
	    v�tan tipu j�rjekorrast - see on v
		for(i = 1; i <= n; i++)				//vaatan l�bi k�ik tipud ehk siis otsin �les k�ik naabrid ja teen nendega j�rgmist (saab siis connections tabelist)
			if(a[v][i]==1 && !visited[i]) // kui on v-le naaber ja ei ole juba k�lastatud,
				queue[++r] = i;				// siis panen naabri j�rjekorra l�ppu
				label[i] = label[v] + 1;	// tipu i kaugus alguspunktist on uuritava tipu v kaugus + 1
				prev[i] = v;				// tippu i tulin tipust v
		visited[v] = 1;						// m�rgin ennist j�rjekorrast v�etud tipu k�lastatuks
	}

}

void main() {
int v;
printf("Enter the number of vertices: ");
scanf("%d",&n);
// Algv��rtustamised 
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
queue[++r] = v;   // panen esimese tipu j�rjekorda, et sealt siis edasi juba tippe v�tta ...
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
