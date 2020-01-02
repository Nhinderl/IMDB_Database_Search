/**
 * Name: Noah Hinderle
 * Student Number: 1053077
 * Email: nhinderl@uoguelph.ca
*/

struct name_node{

    char *key;
    struct name_basics *data;
    struct name_node *RChild;
    struct name_node *LChild;

};

struct name_node_smaller{

    struct name_basics *data;
    struct name_node_smaller *RChild;
    struct name_node_smaller *LChild;

};

struct title_node{

    char *key;
    struct title_basics *data;
    struct title_node *RChild;
    struct title_node *LChild;

};

struct title_node_smaller{

    struct title_basics *data;
    struct title_node_smaller *RChild;
    struct title_node_smaller *LChild;

};

struct principal_node{

    char *key;
    struct title_principals *data;
    struct principal_node *RChild;
    struct principal_node *LChild;

};

struct name_node *makeNconstTree(int, struct name_basics *);
struct name_node_smaller *makeNameTree(int, struct name_basics *);
struct title_node *makeTconstTree(int, struct title_basics *);
struct title_node_smaller *makeTitleTree(int, struct title_basics *);
struct principal_node *makePrincipalTconstTree(int, struct title_principals *);
struct principal_node *makePrincipalNconstTree(int, struct title_principals *);
void writeNconstToTree(struct name_node *, struct name_node *);
void writeNameToTree(struct name_node_smaller *, struct name_node_smaller *);
void writeTconstToTree(struct title_node *, struct title_node *);
void writeTitleToTree(struct title_node_smaller *, struct title_node_smaller *);
void writePrincipalTconstToTree(struct principal_node *, struct principal_node *);
void writePrincipalNconstToTree(struct principal_node *, struct principal_node *);
char *searchByNconst(struct name_node *, char *);
char *searchByName(struct name_node_smaller *, char *);
char *searchByTitle(struct title_node_smaller *, char *);
char *searchByTconst(struct title_node *, char *);
struct principal_node *searchByPrincipalTconst(struct principal_node *, char *);
struct principal_node *searchByPrincipalNconst(struct principal_node *, char *);