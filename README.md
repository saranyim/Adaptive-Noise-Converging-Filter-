!!! This function I ask ChatGPT to crate for me and it work !!!

Convergence Term:

When the difference (delta) is below the noise threshold, a small corrective term (CONVERGENCE_RATE * delta) ensures that SmoothData slowly approaches RawData.
This prevents the filter from "sticking" at an incorrect value due to suppressed updates.
Adaptive Alpha for Large Differences:

The filter responds more aggressively to significant changes (delta > NOISE_THRESHOLD) by dynamically increasing the smoothing factor (alpha).
Clamped Alpha:

The adaptive alpha is capped at ALPHA_MAX to avoid overshooting or oscillations.


Simulation Example
Raw Data (mV)	Smoothed Data (mV)	Notes
3820	3820	Initial value
3800	3819.8	Converges slowly (delta = -20)
3800	3819.6	Continues slow convergence
3700	3780	Responds quickly (delta = -100)
3700	3765	Gradual approach to real value

Advantages
Smooth Convergence: The SmoothData now reliably approaches RawData, even for small persistent differences.
Noise Suppression: Small fluctuations (noise) are still ignored, ensuring a clean output.
Customizable Convergence Rate: The CONVERGENCE_RATE can be tuned based on how fast you want the filter to adapt to small differences.
