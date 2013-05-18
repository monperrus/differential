#define NS_ERROR_DOM_DOMSTRING_SIZE_ERR -1
#define NS_ERROR_DOM_INDEX_SIZE_ERR 	-2

typedef int PRInt32;
typedef unsigned int PRUint32;
typedef char PRUnichar;
typedef int PRBool;
typedef int nsresult;
typedef struct {} nsIDocument;
typedef void * nsCOMPtr;

extern void * memcpy(PRUnichar *, PRUnichar *, PRInt32);
extern nsIDocument * GetCurrentDoc(void);
extern PRBool nsContentUtils_HasMutationListeners(void);
extern void *GetCurrentValueAtom(void);
extern void nsNodeUtils_CharacterDataWillChange(void);

nsresult
 nsGenericDOMDataNode_SetTextInternal(PRUint32 aOffset, PRUint32 aCount,
                                       const PRUnichar* aBuffer,
                                       PRUint32 aLength, PRBool aNotify)
 {

   // sanitize arguments
   PRUint32 textLength;
   if (aOffset > textLength) {
     return NS_ERROR_DOM_INDEX_SIZE_ERR;
   }
 
   nsIDocument *document = GetCurrentDoc();

   PRBool haveMutationListeners = aNotify && nsContentUtils_HasMutationListeners();
 
   nsCOMPtr oldValue;
   if (haveMutationListeners) {
     oldValue = GetCurrentValueAtom();
   }
/*     
  PRUint32 endOffset = aOffset + aCount;
  if (endOffset > textLength) {
    aCount = textLength - aOffset;
    endOffset = textLength;
  }
*/
   if (aNotify) {
     nsNodeUtils_CharacterDataWillChange();
   }
 /*
   if (aOffset == 0 && endOffset == textLength) {
     // Replacing whole text or old text was empty
     mText.SetTo(aBuffer, aLength);
   }
   else if (aOffset == textLength) {
     // Appending to existing
     mText.Append(aBuffer, aLength);
   }
   else {
     // Merging old and new
 
     // Allocate new buffer
     PRInt32 newLength = textLength - aCount + aLength;
     PRUnichar* to = new PRUnichar[newLength];
     NS_ENSURE_TRUE(to, NS_ERROR_OUT_OF_MEMORY);
 
     // Copy over appropriate data
    if (0 != aOffset) {
       mText.CopyTo(to, 0, aOffset);
     }
    if (0 != aLength) {
       memcpy(to + aOffset, aBuffer, aLength * sizeof(PRUnichar));
     }
     if (endOffset != textLength) {
       mText.CopyTo(to + aOffset + aLength, endOffset, textLength - endOffset);
     }
*/
   }

