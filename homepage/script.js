document.addEventListener("DOMContentLoaded", function () {
    // Add a click event listener to all images with the class "dog-image"
    var dogImages = document.querySelectorAll('.dog-image');

    dogImages.forEach(function (image) {
        image.addEventListener('click', function () {
            var breed = this.getAttribute('data-breed');
            alert('You clicked on a ' + breed + ' image!');
        });
    });
});
