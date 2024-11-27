// Constants
#define NOISE_THRESHOLD 50.0f      // Noise floor in mV
#define ALPHA_MIN 0.01f            // Minimum smoothing factor
#define ALPHA_MAX 0.5f             // Maximum smoothing factor
#define CONVERGENCE_RATE 0.001f    // Slow correction factor for small differences

float SmoothData = 0.0f; // Initialize smoothed data

float FilterADC(float RawData, float SmoothData) {
    float delta = RawData - SmoothData;

    // Step 1: Adaptive alpha calculation
    float alpha = ALPHA_MIN;
    if (fabs(delta) > NOISE_THRESHOLD) {
        // Increase alpha for significant changes
        alpha = ALPHA_MIN + (ALPHA_MAX - ALPHA_MIN) * 
                (fabs(delta) - NOISE_THRESHOLD) / (1000.0f - NOISE_THRESHOLD);
        alpha = (alpha > ALPHA_MAX) ? ALPHA_MAX : alpha; // Clamp to max alpha
    }

    // Step 2: Apply primary exponential smoothing
    SmoothData = SmoothData + alpha * delta;

    // Step 3: Add slow convergence for small differences
    if (fabs(delta) < NOISE_THRESHOLD) {
        SmoothData += CONVERGENCE_RATE * delta;
    }

    return SmoothData;
}
