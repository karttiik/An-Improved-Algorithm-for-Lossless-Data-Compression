#define MAX_TREE_HTT 127

// A Huffman tree node
typedef struct MinimumHeapNode {

	// One of the input characters
	char data;
	// Frequency of the character
	unsigned freq;
	// Left and right child of this node
	struct MinimumHeapNode *left, *right;
}MinimumHeapNode;

typedef struct MinimumHeap {

	// Current size of min heap
	unsigned size;
	// capacity of min heap
	unsigned capacity;
	// Array of MinimumHeap node pointers
	MinimumHeapNode** array;
}MinimumHeap;

// function allocate a new min heap node with given character and frequency of the character
MinimumHeapNode* newerNode(char data, unsigned freq) {

	MinimumHeapNode* temp = (MinimumHeapNode*)malloc(sizeof(MinimumHeapNode));

	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;

	return temp;
}

// function to create a min heap of given capacity
MinimumHeap* createMinimumHeap(unsigned capacity) {

	MinimumHeap* MinimumHeap = (struct MinimumHeap*)malloc(sizeof(MinimumHeap));

	// current size is 0
	MinimumHeap->size = 0;
	MinimumHeap->capacity = capacity;
	MinimumHeap->array = (MinimumHeapNode**)malloc(MinimumHeap->capacity * sizeof(MinimumHeapNode*));
	return MinimumHeap;
}

// function to swap two min heap nodes
void swapMinimumHeapNode(MinimumHeapNode** a,
					MinimumHeapNode** b) {

	MinimumHeapNode* t = *a;
	*a = *b;
	*b = t;
}

// MinimumHeapify function.
void MinimumHeapify(MinimumHeap* MinimumHeap, int idx) {

	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < MinimumHeap->size && MinimumHeap->array[left]->
freq < MinimumHeap->array[smallest]->freq)
		smallest = left;

	if (right < MinimumHeap->size && MinimumHeap->array[right]->
freq < MinimumHeap->array[smallest]->freq)
		smallest = right;

	if (smallest != idx) {
		swapMinimumHeapNode(&MinimumHeap->array[smallest],
						&MinimumHeap->array[idx]);
		MinimumHeapify(MinimumHeap, smallest);
	}
}

// function to check if size of heap is 1 or not
int isSizeONE(MinimumHeap* MinimumHeap) {

	return (MinimumHeap->size == 1);
}

// function to extract minimum value node from heap
MinimumHeapNode* extractMinimum(MinimumHeap* MinimumHeap) {

	MinimumHeapNode* temp = MinimumHeap->array[0];
	MinimumHeap->array[0]
		= MinimumHeap->array[MinimumHeap->size - 1];

	--MinimumHeap->size;
	MinimumHeapify(MinimumHeap, 0);

	return temp;
}

// function to insert a new node to Min Heap
void insertMinimumHeap(MinimumHeap* MinimumHeap,
				MinimumHeapNode* MinimumHeapNode) {

	++MinimumHeap->size;
	int i = MinimumHeap->size - 1;

	while (i && MinimumHeapNode->freq < MinimumHeap->array[(i - 1) / 2]->freq) {

		MinimumHeap->array[i] = MinimumHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}

	MinimumHeap->array[i] = MinimumHeapNode;
}

// function to build min heap
void buildMinimumHeap(MinimumHeap* MinimumHeap) {

	int n = MinimumHeap->size - 1;
	int i;

	for (i = (n - 1) / 2; i >= 0; --i)
		MinimumHeapify(MinimumHeap, i);
}

// function to check if this node is leaf
int isLEaf(MinimumHeapNode* root) {

	return !(root->left) && !(root->right);
}

// Creates a min heap of capacity equal to size and inserts all character of
// data[] in min heap. Initially size of min heap is equal to capacity
MinimumHeap* createAndBuildMinimumHeap(char data[], int freq[], int size) {

	MinimumHeap* MinimumHeap = createMinimumHeap(size);

	for (int i = 0; i < size; ++i)
		MinimumHeap->array[i] = newerNode(data[i], freq[i]);

	MinimumHeap->size = size;
	buildMinimumHeap(MinimumHeap);

	return MinimumHeap;
}

// The main function that builds Huffman tree
MinimumHeapNode* buildingHuffmanTree(char data[], int freq[], int size) {

	MinimumHeapNode *left, *right, *top;

	// Create a min heap of capacity equal to size. Initially, there are
	// modes equal to size.
	MinimumHeap* MinimumHeap = createAndBuildMinimumHeap(data, freq, size);

	// Iterate while size of heap doesn't become 1
	while (!isSizeONE(MinimumHeap)) {

		// Extract the two minimum freq items from min heap
		left = extractMinimum(MinimumHeap);
		right = extractMinimum(MinimumHeap);

		// Create a new internal node with frequency equal to the
		// sum of the two nodes frequencies. Make the two extracted node as
		// left and right children of this new node. Add this node to the min heap
		// '$' is a special value for internal nodes, not used
		top = newerNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		insertMinimumHeap(MinimumHeap, top);
	}

	// The remaining node is the root node and the tree is complete.
	return extractMinimum(MinimumHeap);
}

// Prints huffman codes from the root of Huffman Tree.
// It uses arr[] to store codes
void decode_file(MinimumHeapNode* root) {

	FILE *f1,*f2;
	char ch;
	f1=fopen("huff_net.dat","r");
	f2=fopen("orignal.txt","w");
    MinimumHeapNode* curr = root;
		while((ch=fgetc(f1))!=EOF) {
			if (ch == '0')
				 curr = curr->left;
			else
				 curr = curr->right;
      if (curr->left==NULL && curr->right==NULL) {
				 fprintf(f2,"%c",curr->data);
         curr = root;
       }
		}
		fclose(f1);
		fclose(f2);
}
// Function that builds a Huffman Tree and print codes by traversing the built Huffman Tree
void call_decoder(char data[], int freq[], int size)
{
	char ans;
	struct MinimumHeapNode* root = buildingHuffmanTree(data, freq, size);
	printf("Enter y to continue:");
	scanf("%c",&ans);
	if (ans=='y' || ans=='Y') {
		decode_file(root);
		printf("File decoded successfully \n");
		printf("Decompressed file is in: original.txt \n");
	}
	else {
		printf("Wrong input!");
	}
}
