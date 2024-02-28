class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        knowledge_dict = {k: v for k, v in knowledge}
        result = []
        key = ""
        in_brackets = False
        
        for char in s:
            if char == '(':
                in_brackets = True
            elif char == ')':
                in_brackets = False
                result.append(knowledge_dict.get(key, "?"))
                key = ""
            elif in_brackets:
                key += char
            else:
                result.append(char)
                
        return "".join(result)