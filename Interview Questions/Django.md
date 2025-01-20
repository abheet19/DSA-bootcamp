# Django REST Framework Interview Questions

This file contains a curated set of Django REST Framework interview questions covering fundamental concepts, advanced topics, authentication, serialization, viewsets, testing, and more, along with code snippets and explanations.

## Table of Contents

- [Fundamentals](#fundamentals)
- [Advanced Topics](#advanced-topics)
- [Authentication and Permissions](#authentication-and-permissions)
- [Serialization](#serialization)
- [Viewsets and Routers](#viewsets-and-routers)
- [Testing](#testing)
- [Performance Optimization](#performance-optimization)
- [Error Handling](#error-handling)
- [Documentation](#documentation)

## Fundamentals

### 1. What is Django REST Framework?

Django REST Framework (DRF) is a powerful and flexible toolkit for building Web APIs in Django. It provides features like serialization, authentication, viewsets, and browsable APIs.

```python
from rest_framework import serializers, viewsets

class UserSerializer(serializers.ModelSerializer):
    class Meta:
        model = User
        fields = ['id', 'username', 'email']

class UserViewSet(viewsets.ModelViewSet):
    queryset = User.objects.all()
    serializer_class = UserSerializer
```

### 2. Explain the difference between serializers and Django forms.

Serializers in DRF handle the conversion between complex data types like querysets and Python native types, facilitating JSON representation. Django forms are primarily used for validating and processing user input in web forms.

## Advanced Topics

### 3. How does pagination work in DRF?

DRF provides built-in pagination classes like `PageNumberPagination`, `LimitOffsetPagination`, and `CursorPagination` to control the amount of data returned in API responses.

```python
# settings.py
REST_FRAMEWORK = {
    'DEFAULT_PAGINATION_CLASS': 'rest_framework.pagination.PageNumberPagination',
    'PAGE_SIZE': 10
}
```

### 4. What are generic views in DRF?

Generic views in DRF provide common patterns for building APIs, reducing boilerplate code. They include `ListAPIView`, `RetrieveAPIView`, `CreateAPIView`, etc.

```python
from rest_framework import generics

class UserList(generics.ListCreateAPIView):
    queryset = User.objects.all()
    serializer_class = UserSerializer
```

## Authentication and Permissions

### 5. How do you implement token-based authentication in DRF?

Use DRF's `TokenAuthentication` class to manage token-based authentication.

```python
# settings.py
REST_FRAMEWORK = {
    'DEFAULT_AUTHENTICATION_CLASSES': [
        'rest_framework.authentication.TokenAuthentication',
    ],
}

# Obtain token
from rest_framework.authtoken.views import obtain_auth_token

urlpatterns = [
    path('api-token-auth/', obtain_auth_token),
]
```

### 6. Explain the role of permissions in DRF.

Permissions determine whether a user can perform a certain action. DRF provides various permission classes like `IsAuthenticated`, `IsAdminUser`, etc., and allows custom permissions.

```python
from rest_framework.permissions import IsAuthenticated

class UserViewSet(viewsets.ModelViewSet):
    queryset = User.objects.all()
    serializer_class = UserSerializer
    permission_classes = [IsAuthenticated]
```

## Serialization

### 7. What is the difference between `Serializer` and `ModelSerializer`?

`ModelSerializer` provides a shortcut for creating serializers that automatically include fields from a model, reducing boilerplate code.

```python
from rest_framework import serializers

class UserSerializer(serializers.ModelSerializer):
    class Meta:
        model = User
        fields = ['id', 'username', 'email']
```

### 8. How do you handle nested serializers?

Nested serializers allow you to include related data within a serializer.

```python
class ProfileSerializer(serializers.ModelSerializer):
    class Meta:
        model = Profile
        fields = ['bio', 'location']

class UserSerializer(serializers.ModelSerializer):
    profile = ProfileSerializer()

    class Meta:
        model = User
        fields = ['id', 'username', 'email', 'profile']
```

## Viewsets and Routers

### 9. What are viewsets in DRF?

Viewsets combine the logic for multiple views into a single class, providing actions like `list`, `retrieve`, `create`, `update`, and `destroy`.

### 10. How do routers work in DRF?

Routers automatically generate URL patterns for viewsets, simplifying the routing configuration.

```python
from rest_framework import routers
from .views import UserViewSet

router = routers.DefaultRouter()
router.register(r'users', UserViewSet)

urlpatterns = [
    path('', include(router.urls)),
]
```

## Testing

### 11. How do you perform API testing in DRF?

Use Django's test framework along with DRF's `APIClient` to write tests for API endpoints.

```python
from rest_framework.test import APITestCase

class UserTests(APITestCase):
    def test_create_user(self):
        url = '/users/'
        data = {'username': 'testuser', 'email': 'test@example.com'}
        response = self.client.post(url, data, format='json')
        self.assertEqual(response.status_code, 201)
```

## Performance Optimization

### 12. How do you optimize API performance in DRF?

Use techniques like query optimization, caching, pagination, and selective field loading to enhance API performance.

## Error Handling

### 13. How does DRF handle exceptions?

DRF provides custom exception handlers to return consistent error responses.

```python
# settings.py
REST_FRAMEWORK = {
    'EXCEPTION_HANDLER': 'my_project.my_app.utils.custom_exception_handler'
}
```

## Documentation

### 14. How do you document APIs in DRF?

Use tools like Swagger or DRF's built-in browsable API to provide interactive API documentation.

```python
from rest_framework import schemas
from rest_framework_swagger.views import get_swagger_view

schema_view = get_swagger_view(title='API Documentation')

urlpatterns = [
    path('docs/', schema_view),
]
```

## Additional Questions

### 15. How do you implement throttling in DRF?

Throttling restricts the rate of API requests to prevent abuse and ensure fair usage.

```python
# settings.py
REST_FRAMEWORK = {
    'DEFAULT_THROTTLE_CLASSES': [
        'rest_framework.throttling.UserRateThrottle',
    ],
    'DEFAULT_THROTTLE_RATES': {
        'user': '1000/day',
    }
}
```

### 16. What is the purpose of `APIView` in DRF?

`APIView` is the base class for all class-based views in DRF, providing essential functionality like request parsing and authentication.

```python
from rest_framework.views import APIView
from rest_framework.response import Response

class HelloWorldView(APIView):
    def get(self, request):
        return Response({"message": "Hello, World!"})
```

### 17. How do you handle permissions dynamically in DRF?

Use custom permission classes or override the `get_permissions` method in viewsets to handle permissions based on the request or user.

```python
from rest_framework.permissions import BasePermission

class IsOwner(BasePermission):
    def has_object_permission(self, request, view, obj):
        return obj.owner == request.user

class PostViewSet(viewsets.ModelViewSet):
    # ...existing code...
    def get_permissions(self):
        if self.action == 'update':
            return [IsOwner()]
        return super().get_permissions()
```

### 18. Explain the use of `filter_backends` in DRF.

`filter_backends` allow you to specify how querysets can be filtered or ordered. Common backends include `DjangoFilterBackend`, `SearchFilter`, and `OrderingFilter`.

```python
from rest_framework import viewsets, filters
from django_filters.rest_framework import DjangoFilterBackend

class ProductViewSet(viewsets.ModelViewSet):
    queryset = Product.objects.all()
    serializer_class = ProductSerializer
    filter_backends = [DjangoFilterBackend, filters.SearchFilter, filters.OrderingFilter]
    filterset_fields = ['category', 'price']
    search_fields = ['name', 'description']
    ordering_fields = ['price', 'created_at']
```

### 19. How do you handle file uploads in DRF?

Use serializers with `FileField` or `ImageField` and handle the file data in the view.

```python
from rest_framework import serializers, viewsets

class UploadSerializer(serializers.Serializer):
    file = serializers.FileField()

class FileUploadViewSet(viewsets.ViewSet):
    def create(self, request):
        serializer = UploadSerializer(data=request.data)
        if serializer.is_valid():
            file = serializer.validated_data['file']
            # Handle the uploaded file
            return Response({"status": "file uploaded"})
        return Response(serializer.errors, status=400)
```

### 20. What is the purpose of `BrowsableAPIRenderer` in DRF?

`BrowsableAPIRenderer` provides a web-based interface for interacting with the API, useful for testing and debugging.

```python
# settings.py
REST_FRAMEWORK = {
    'DEFAULT_RENDERER_CLASSES': (
        'rest_framework.renderers.JSONRenderer',
        'rest_framework.renderers.BrowsableAPIRenderer',
    )
}
```

### 21. How do you implement custom renderers in DRF?

Create a custom renderer class by subclassing `BaseRenderer` and overriding the `render` method.

```python
from rest_framework.renderers import BaseRenderer

class PlainTextRenderer(BaseRenderer):
    media_type = 'text/plain'
    format = 'txt'

    def render(self, data, media_type=None, renderer_context=None):
        return data.encode('utf-8')
```

### 22. Explain the use of `ContentNegotiation` in DRF.

Content negotiation determines the media type of the response based on client preferences and available renderers.

```python
from rest_framework.negotiation import DefaultContentNegotiation

class CustomContentNegotiation(DefaultContentNegotiation):
    def select_renderer(self, request, renderers, format_suffix):
        # Custom logic for selecting renderer
        return super().select_renderer(request, renderers, format_suffix)
```

### 23. What is `SchemaGenerator` in DRF?

`SchemaGenerator` creates schema definitions for the API, which can be used for documentation and client generation.

```python
from rest_framework.schemas import get_schema_view

schema_view = get_schema_view(title="My API")
```

### 24. How do you implement throttling rates per user in DRF?

Define custom throttle classes or set rate limits in settings for different user types.

```python
# settings.py
REST_FRAMEWORK = {
    'DEFAULT_THROTTLE_CLASSES': [
        'rest_framework.throttling.UserRateThrottle',
    ],
    'DEFAULT_THROTTLE_RATES': {
        'user': '1000/day',
        'anon': '100/day',
    }
}
```

### 25. How do you use `action` decorators in DRF ViewSets?

`@action` decorators add custom actions to viewsets beyond the standard CRUD operations.

```python
from rest_framework.decorators import action
from rest_framework.response import Response

class UserViewSet(viewsets.ModelViewSet):
    # ...existing code...

    @action(detail=True, methods=['post'])
    def set_password(self, request, pk=None):
        user = self.get_object()
        user.set_password(request.data['password'])
        user.save()
        return Response({'status': 'password set'})
```

### 26. Explain how to use `Nested Routers` in DRF.

Nested Routers allow you to define routes that nest resources, representing relationships between models.

```python
from rest_framework_nested import routers
from .views import UserViewSet, ProfileViewSet

router = routers.DefaultRouter()
router.register(r'users', UserViewSet)

users_router = routers.NestedDefaultRouter(router, r'users', lookup='user')
users_router.register(r'profiles', ProfileViewSet, basename='user-profiles')

urlpatterns = [
    path('', include(router.urls)),
    path('', include(users_router.urls)),
]
```

### 27. How do you implement rate limiting in DRF?

Use throttle classes to limit the rate of requests per user or globally.

```python
from rest_framework.throttling import UserRateThrottle

class BurstRateThrottle(UserRateThrottle):
    rate = '10/min'

class SustainedRateThrottle(UserRateThrottle):
    rate = '100/day'

class MyViewSet(viewsets.ModelViewSet):
    queryset = MyModel.objects.all()
    serializer_class = MySerializer
    throttle_classes = [BurstRateThrottle, SustainedRateThrottle]
```

### 28. How do you customize pagination responses in DRF?

Override the pagination class to modify the pagination response structure.

```python
from rest_framework.pagination import PageNumberPagination
from rest_framework.response import Response

class CustomPagination(PageNumberPagination):
    page_size = 10

    def get_paginated_response(self, data):
        return Response({
            'links': {
               'next': self.get_next_link(),
               'previous': self.get_previous_link()
            },
            'count': self.page.paginator.count,
            'results': data
        })

# settings.py
REST_FRAMEWORK = {
    'DEFAULT_PAGINATION_CLASS': 'path.to.CustomPagination',
}
```

### 29. Explain the use of mixins in DRF ViewSets.

Mixins provide reusable behaviors for viewsets, such as `CreateModelMixin`, `RetrieveModelMixin`, etc., enabling flexible view configurations.

```python
from rest_framework import mixins, viewsets

class ReadOnlyViewSet(mixins.RetrieveModelMixin,
                      mixins.ListModelMixin,
                      viewsets.GenericViewSet):
    queryset = MyModel.objects.all()
    serializer_class = MySerializer
```