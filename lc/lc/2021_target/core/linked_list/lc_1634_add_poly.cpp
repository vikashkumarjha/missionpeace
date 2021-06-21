class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        // Create a head node, and 2 other pointers in poly1 and poly2 starting from the header node, saying p1 and p2.
        // 1) If p1's pow > p2's pow, p1 becomes head's next pointer, and p1 move to the next node in poly1;
        // 2) If p2's pow > p1's pow, p2 becomes head's next pointer, and p2 move to the next node in poly2;
        // 3) If p1's pow == p2's pow, add them together. If the coefficient is 0, both p1 and p2 move to the next nodes.
        // Otherwise create a new node with updated coefficient, and make it as the next pointer of the head.
        // Finally return the head pointer.
        PolyNode* head = new PolyNode(), *headCopy = head, *p1 = poly1, *p2 = poly2;
        while (p1 && p2)
        {
            int pow1 = p1->power, pow2 = p2->power, c1 = p1->coefficient, c2 = p2->coefficient;
            if (pow1 > pow2)
            {
                head->next = new PolyNode(c1, pow1);
                p1 = p1->next;
                head = head->next;
            }
            else if (pow1 < pow2)
            {
                head->next = new PolyNode(c2, pow2);
                p2 = p2->next;
                head = head->next;
            }
            else
            {
                if (c1 + c2 != 0)
                {
                    head->next = new PolyNode(c1 + c2, pow1);
                    head = head->next;
                }

                p1 = p1->next, p2 = p2->next;
            }
        }

        head->next = p1 ? p1 : p2;
        return headCopy->next;
    }
};
