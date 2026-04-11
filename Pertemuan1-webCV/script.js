const btn = document.getElementById("toggleBtn");
const tooltip = document.querySelector(".tooltip");

btn.addEventListener("click", () => {
    document.body.classList.toggle("dark");

    if (document.body.classList.contains("dark")) {
        localStorage.setItem("mode", "dark");
        tooltip.textContent = "Switch to Light Mode";
    } else {
        localStorage.setItem("mode", "light");
        tooltip.textContent = "Switch to Dark Mode";
    }
});

window.addEventListener("load", () => {
    if (localStorage.getItem("mode") === "dark") {
        document.body.classList.add("dark");
        tooltip.textContent = "Switch to Light Mode";
    }
});

document.querySelectorAll(".carousel").forEach(carousel => {

const track = carousel.querySelector(".carousel-track");
const slides = track.querySelectorAll("img");
const dotsContainer = carousel.querySelector(".carousel-dots");

let currentIndex = 0;

slides.forEach((_, index) => {
    const dot = document.createElement("span");
    dot.classList.add("dot");

    if (index === 0) dot.classList.add("active");

    dot.addEventListener("click", () => {
        currentIndex = index;
        updateSlide();
    });

    dotsContainer.appendChild(dot);
});

const dots = dotsContainer.querySelectorAll(".dot");

function updateSlide() {
    const slideWidth = slides[0].clientWidth;
    track.style.transform = `translateX(-${slideWidth * currentIndex}px)`;

    dots.forEach(dot => dot.classList.remove("active"));
    dots[currentIndex].classList.add("active");
    }

});

const reveals = document.querySelectorAll(".reveal");

const observer = new IntersectionObserver((entries) => {
    entries.forEach((entry, index) => {
        if (entry.isIntersecting) {
            entry.target.style.transitionDelay = `${index * 0.1}s`;
            entry.target.classList.add("active");
        }
    });
}, {
    threshold: 0.15
});

reveals.forEach(el => observer.observe(el));

