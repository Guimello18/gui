#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

void parseXML(const char *filename) {
    xmlDoc *document = xmlReadFile(filename, NULL, 0);
    if (document == NULL) {
        fprintf(stderr, "Failed to parse %s\n", filename);
        return;
    }

    xmlNode *root = xmlDocGetRootElement(document);
    printf("Root Element: %s\n", root->name);

    // Percorre os nós do XML
    for (xmlNode *node = root->children; node; node = node->next) {
        if (node->type == XML_ELEMENT_NODE) {
            printf("Node: %s\n", node->name);
            xmlChar *content = xmlNodeGetContent(node);
            printf("Content: %s\n", content);
            xmlFree(content);
        }
    }

    xmlFreeDoc(document);
    xmlCleanupParser();
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file.xml>\n", argv[0]);
        return 1;
    }

    parseXML(argv[1]);
    return 0;
}

