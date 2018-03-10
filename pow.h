
struct proof {
    bool found;
    int length;
    double time;
    int sequence;
    char* hash;
};

bool check_pow(char* hash, int n);
void init_proofs(struct proof *proofs, int n, int c);
bool proofs_completed(struct proof *proofs, int c);
void print_proof(struct proof sample);