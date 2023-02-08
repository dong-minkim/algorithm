class Solution {
    public int[] solution(long[] numbers) {
        int[] answer = new int[numbers.length];

        for (int index = 0; index < numbers.length; index++) {

            String binary = Long.toBinaryString(numbers[index]);

            int exp = 0;
            while ((int) Math.pow(2, ++exp) - 1 < binary.length()) {
            }
            while (((int) Math.pow(2, exp) - 1 != binary.length())) {
                binary = "0" + binary;
            }
            if (validate(binary) && binary.charAt((binary.length() - 1) / 2) == '1') {
                answer[index] = 1;
            }
        }
        return answer;
    }

    private boolean validate(String binary) {

        int mid = (binary.length() - 1) / 2;
        char root = binary.charAt(mid);
        String leftChild = binary.substring(0, mid);
        String rightChild = binary.substring(mid + 1);

        if (root == '0' && (leftChild.charAt((leftChild.length() - 1) / 2) == '1'
                || rightChild.charAt((rightChild.length() - 1) / 2) == '1')) {
            return false;
        }

        if (leftChild.length() >= 3) {
            return validate(leftChild) && validate(rightChild);
        }

        return true;
    }
}